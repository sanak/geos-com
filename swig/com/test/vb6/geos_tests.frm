VERSION 5.00
Begin VB.Form GeosTestsForm 
   BorderStyle     =   1  'å≈íË(é¿ê¸)
   Caption         =   "geos_tests"
   ClientHeight    =   5010
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   2070
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   5010
   ScaleWidth      =   2070
   StartUpPosition =   3  'Windows ÇÃä˘íËíl
   Begin VB.CommandButton cmdExit 
      Caption         =   "exit"
      Height          =   375
      Left            =   120
      TabIndex        =   9
      Top             =   4560
      Width           =   1815
   End
   Begin VB.CommandButton cmdVersion 
      Caption         =   "version"
      Height          =   375
      Left            =   120
      TabIndex        =   8
      Top             =   3960
      Width           =   1815
   End
   Begin VB.CommandButton cmdSrid 
      Caption         =   "srid"
      Height          =   375
      Left            =   120
      TabIndex        =   7
      Top             =   3480
      Width           =   1815
   End
   Begin VB.CommandButton cmdRelations 
      Caption         =   "relations"
      Height          =   375
      Left            =   120
      TabIndex        =   6
      Top             =   3000
      Width           =   1815
   End
   Begin VB.CommandButton cmdOperations 
      Caption         =   "operations"
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   2520
      Width           =   1815
   End
   Begin VB.CommandButton cmdIo 
      Caption         =   "io"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   2040
      Width           =   1815
   End
   Begin VB.CommandButton cmdGeometry 
      Caption         =   "geometry"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   1560
      Width           =   1815
   End
   Begin VB.CommandButton cmdCoordinateSequence 
      Caption         =   "coordinateSequence"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   1080
      Width           =   1815
   End
   Begin VB.CommandButton cmdCombinations 
      Caption         =   "combinations"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   1815
   End
   Begin VB.CommandButton cmdBuffer 
      Caption         =   "buffer"
      Enabled         =   0   'False
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1815
   End
   Begin VB.Line Line1 
      X1              =   120
      X2              =   1920
      Y1              =   4440
      Y2              =   4440
   End
End
Attribute VB_Name = "GeosTestsForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdCombinations_Click()
    Dim test
    Set test = New TestGeosCombinations
    test.testUnion
    test.testIntersection
    test.testDifference
    test.testSymDifference
End Sub

Private Sub cmdCoordinateSequence_Click()
    Dim test
    Set test = New TestCoordinateSequence
    test.testCreate
    test.testSize
    test.testGetterSetter
    'test.testIndexOutOfBounds
    test.testOrdinate
    test.testClone
    test.testDimensions
End Sub

Private Sub cmdExit_Click()
    End
End Sub

Private Sub cmdGeometry_Click()
    Dim test
    Set test = New TestGeometry
    test.testCreatePoint
    'test.testCreatePointIllegal
    test.testCreateLineString
    'test.testCreateLineStringIllegal
    test.testCreateLinearRing
    'test.testCreateLinearRingIllegal
    test.testCreatePolygon
    'test.testCreatePolygonWithHoles
    test.testDistance
End Sub

Private Sub cmdIo_Click()
    Dim test
    Set test = New TestIo
    test.testOutputDimension
    test.testByteOrder
    test.testPoint
    test.testLineString
    test.testPolygon
    test.testMultiPoint
    test.testMultiLineString
    test.testMultiPolygon
    'test.testCollection ' TODO:
    'test.testWktInvalid
    'test.testWkbInvalid
    'test.testHexInvalid
End Sub

Private Sub cmdOperations_Click()
    Dim test
    Set test = New TestGeosOperations
    test.testCentroid
    test.testBuffer
    test.testConvexHull
End Sub

Private Sub cmdRelations_Click()
    Dim test
    Set test = New TestGeosRelations
    test.testContains
    test.testCrosses
    test.testDisjoint
    test.testEquals
    test.testEqualsExact
    test.testIntersects
    'test.testIsWithinDistance ' TODO:
    test.testOverlaps
    test.testRelatePattern
    test.testRelate
    test.testTouches
    test.testWithin
End Sub

Private Sub cmdSrid_Click()
    Dim test
    Set test = New SridTest
    test.testSrid
    test.testWriteSrid
    test.testRoundtripSrid
    test.testReadSRID
End Sub

Private Sub cmdVersion_Click()
    Dim test
    Set test = New TestVersion
    test.testVersions
End Sub
