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

Private Sub Class_Initialize()
    setup "testSrid": testSrid
    setup "testWriteSrid": testWriteSrid
    setup "testRoundtripSrid": testRoundtripSrid
    setup "testReadSRID": testReadSRID
    report
End Sub

Sub testSrid()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
    cs.setX 0, 7
    cs.setY 0, 8
    
    Dim geom1
    Set geom1 = geos.createPoint(cs)
    geom1.setSRID 4326
    
    assertEqual 4326, geom1.getSRID, "geom1.getSRID"
End Sub

Sub testWriteSrid()
    Dim reader
    Set reader = geos.wktReader.new_WktReader()
    Dim geom
    Set geom = reader.read("POINT(7 8)")
    geom.setSRID 4326
    
    Dim writer
    Set writer = geos.wkbWriter.new_WkbWriter()
    ' without srid
    writer.setIncludeSRID False
    Dim hex
    hex = writer.writeHEX(geom)
    assertEqual "01010000000000000000001C400000000000002040", hex, "hex"
    
    ' with srid
    writer.setIncludeSRID True
    hex = writer.writeHEX(geom)
    assertEqual "0101000020E61000000000000000001C400000000000002040", hex, "hex"
End Sub

Sub testRoundtripSrid()
    Dim reader
    Set reader = geos.wktReader.new_WktReader()
    Dim geom1
    Set geom1 = reader.read("POINT(7 8)")
    geom1.setSRID 4326
    assertEqual 4326, geom1.getSRID, "geom1.getSRID"
    
    Dim writer
    Set writer = geos.wkbWriter.new_WkbWriter()
    writer.setIncludeSRID True
    Dim hex
    hex = writer.writeHEX(geom1)
    
    Set reader = Nothing
    Set reader = geos.wkbReader.new_WkbReader()
    Dim geom2
    Set geom2 = reader.readHEX(hex)
    assertEqual 4326, geom2.getSRID, "geom2.getSRID"
End Sub

Sub testReadSRID()
    ' srid=4326;POINT(7 8)
    Dim xdr
    xdr = "0101000020E61000000000000000001C400000000000002040"
    
    Dim reader
    Set reader = geos.wkbReader.new_WkbReader()
    Dim geom
    Set geom = reader.readHEX(xdr)
    
    assertEqual 7, geom.getCoordSeq.getX(0), "geom.getCoordSeq.getX(0)"
    assertEqual 8, geom.getCoordSeq.getY(0), "geom.getCoordSeq.getY(0)"
    assertEqual 4326, geom.getSRID, "geom.getSRID"
End Sub
