VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TestCoordinateSequence"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Sub Class_Initialize()
    setup "testCreate": testCreate
    setup "testSize": testSize
    setup "testGetterSetter": testGetterSetter
    'setup "testIndexOutOfBounds": testIndexOutOfBounds
    setup "testOrdinate": testOrdinate
    setup "testClone": testClone
    setup "testDimensions": testDimensions
    report
End Sub

Sub testCreate()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
    assertEqual "ICoordinateSequence", TypeName(cs), "TypeName(cs)"
End Sub

Sub testSize()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(7, 2)
    assertEqual 7, cs.getSize, "cs.getSize"
End Sub

Sub testGetterSetter()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3)
    cs.setX 0, 3
    cs.setY 0, 4
    cs.setZ 0, 5
    cs.setX 1, 6
    cs.setY 1, 7
    cs.setZ 1, 8
    assertEqual 3, cs.getX(0), "cs.getX(0)"
    assertEqual 4, cs.getY(0), "cs.getY(0)"
    assertEqual 5, cs.getZ(0), "cs.getZ(0)"
    assertEqual 6, cs.getX(1), "cs.getX(1)"
    assertEqual 7, cs.getY(1), "cs.getY(1)"
    assertEqual 8, cs.getZ(1), "cs.getZ(1)"
End Sub

Sub testIndexOutOfBounds()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3)
    cs.setX 2, 6
    cs.setY 2, 6
    cs.setZ 2, 6
End Sub

Sub testOrdinate()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
    cs.setOrdinate 0, 0, 2
    cs.setOrdinate 0, 1, 3
    cs.setOrdinate 0, 2, 4
    
    assertEqual 2, cs.getOrdinate(0, 0), "cs.getOrdinate(0, 0)"
    assertEqual 3, cs.getOrdinate(0, 1), "cs.getOrdinate(0, 1)"
    assertEqual 4, cs.getOrdinate(0, 2), "cs.getOrdinate(0, 2)"
End Sub

Sub testClone()
    Dim cs1
    Set cs1 = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
    cs1.setX 0, 2
    cs1.setY 0, 3
    cs1.setZ 0, 4
    
    Dim cs2
    Set cs2 = cs1.Clone
    
    'assert (cs1 = cs2) ' TODO:
    assertEqual 2, cs2.getX(0), "cs2.getX(0)"
    assertEqual 3, cs2.getY(0), "cs2.getY(0)"
    assertEqual 4, cs2.getZ(0), "cs2.getZ(0)"
    
    cs2.setX 0, 5
    cs2.setY 0, 6
    cs2.setZ 0, 7
    
    assertEqual 2, cs1.getX(0), "cs1.getX(0)"
    assertEqual 3, cs1.getY(0), "cs1.getY(0)"
    assertEqual 4, cs1.getZ(0), "cs1.getZ(0)"
    
    assertEqual 5, cs2.getX(0), "cs2.getX(0)"
    assertEqual 6, cs2.getY(0), "cs2.getY(0)"
    assertEqual 7, cs2.getZ(0), "cs2.getZ(0)"
End Sub

Sub testDimensions()
    Dim cs
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
    assertEqual 3, cs.getDimensions, "cs.getDimensions"
End Sub
