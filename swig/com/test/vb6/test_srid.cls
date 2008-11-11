VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SridTest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Sub testSrid()
    MsgBox "testSrid"
    
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
    cs.setX 0, 7
    cs.setY 0, 8
    
    Dim geom1
    Set geom1 = geos.createPoint(cs)
    geom1.setSRID 4326
    
    assertEqual 4326, geom1.getSRID, "geom1.getSRID"
    
    report
End Sub

Sub testWriteSrid()
    MsgBox "testWriteSrid"
    
    Dim reader
    Set reader = geos.WktReader.new_WktReader()
    Dim geom
    Set geom = reader.read("POINT(7 8)")
    geom.setSRID 4326
    
    Dim writer
    Set writer = geos.WkbWriter.new_WkbWriter()
    ' without srid
    writer.setIncludeSRID False
    Dim hex
    hex = writer.writeHEX(geom)
    assertEqual "01010000000000000000001C400000000000002040", hex, "hex"
    
    ' with srid
    writer.setIncludeSRID True
    hex = writer.writeHEX(geom)
    assertEqual "0101000020E61000000000000000001C400000000000002040", hex, "hex"
    
    report
End Sub

Sub testRoundtripSrid()
    MsgBox "testRoundtripSrid"
    
    Dim reader
    Set reader = geos.WktReader.new_WktReader()
    Dim geom1
    Set geom1 = reader.read("POINT(7 8)")
    geom1.setSRID 4326
    assertEqual 4326, geom1.getSRID, "geom1.getSRID"
    
    Dim writer
    Set writer = geos.WkbWriter.new_WkbWriter()
    writer.setIncludeSRID True
    Dim hex
    hex = writer.writeHEX(geom1)
    
    Set reader = Nothing
    Set reader = geos.WkbReader.new_WkbReader()
    Dim geom2
    Set geom2 = reader.readHEX(hex)
    assertEqual 4326, geom2.getSRID, "geom2.getSRID"
    
    report
End Sub

Sub testReadSRID()
    MsgBox "testReadSRID"
    
    ' srid=4326;POINT(7 8)
    Dim xdr
    xdr = "0101000020E61000000000000000001C400000000000002040"
    
    Dim reader
    Set reader = geos.WkbReader.new_WkbReader()
    Dim geom
    Set geom = reader.readHEX(xdr)
    
    assertEqual 7, geom.getCoordSeq.getX(0), "geom.getCoordSeq.getX(0)"
    assertEqual 8, geom.getCoordSeq.getY(0), "geom.getCoordSeq.getY(0)"
    assertEqual 4326, geom.getSRID, "geom.getSRID"
    
    report
End Sub
