VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "ieframe.dll"
Begin VB.Form frmMain 
   BorderStyle     =   1
   Caption         =   "geos_com_tester"
   ClientHeight    =   8010
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   9825
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   8010
   ScaleWidth      =   9825
   StartUpPosition =   3
   Begin VB.Frame frmOperation 
      Caption         =   "Operation"
      Height          =   2295
      Left            =   120
      TabIndex        =   5
      Top             =   120
      Width           =   3615
      Begin VB.CommandButton cmdClearOperation 
         Caption         =   "Clear"
         Height          =   375
         Left            =   1680
         TabIndex        =   21
         Top             =   1800
         Width           =   855
      End
      Begin VB.ComboBox cmbOperation 
         Height          =   300
         Left            =   120
         Style           =   2
         TabIndex        =   20
         Top             =   240
         Width           =   3375
      End
      Begin VB.TextBox txtArg 
         Height          =   270
         Index           =   2
         Left            =   1680
         TabIndex        =   18
         Top             =   1440
         Width           =   1815
      End
      Begin VB.TextBox txtArg 
         Height          =   270
         Index           =   1
         Left            =   1680
         TabIndex        =   17
         Top             =   1080
         Width           =   1815
      End
      Begin VB.TextBox txtArg 
         Height          =   270
         Index           =   0
         Left            =   1680
         TabIndex        =   16
         Top             =   720
         Width           =   1815
      End
      Begin VB.CommandButton cmdExecOperation 
         Caption         =   "Exec"
         Height          =   375
         Left            =   2640
         TabIndex        =   12
         Top             =   1800
         Width           =   855
      End
      Begin VB.Label lblArg 
         Caption         =   "Argument1"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   15
         Top             =   720
         Width           =   1575
      End
      Begin VB.Label lblArg 
         Caption         =   "Argument2"
         Height          =   255
         Index           =   1
         Left            =   120
         TabIndex        =   14
         Top             =   1080
         Width           =   1575
      End
      Begin VB.Label lblArg 
         Caption         =   "Argument3"
         Height          =   255
         Index           =   2
         Left            =   120
         TabIndex        =   13
         Top             =   1440
         Width           =   1575
      End
   End
   Begin SHDocVwCtl.WebBrowser ctlCanvas 
      Height          =   5895
      Left            =   3840
      TabIndex        =   2
      Top             =   120
      Width           =   5895
      ExtentX         =   10398
      ExtentY         =   10398
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin VB.TextBox txtResult 
      Height          =   1815
      Left            =   3840
      MultiLine       =   -1  'True
      ScrollBars      =   2
      TabIndex        =   0
      Top             =   6120
      Width           =   5895
   End
   Begin VB.Frame Frame1 
      Caption         =   "Test Case"
      Height          =   1095
      Left            =   120
      TabIndex        =   1
      Top             =   2520
      Width           =   3615
      Begin MSComDlg.CommonDialog cdlTestCase 
         Left            =   1920
         Top             =   600
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
      Begin VB.ComboBox cmbTestCase 
         Height          =   300
         Left            =   120
         Style           =   2
         TabIndex        =   4
         Top             =   240
         Width           =   3375
      End
      Begin VB.CommandButton cmdLoadTestCase 
         Caption         =   "Load"
         Height          =   375
         Left            =   2640
         TabIndex        =   3
         Top             =   600
         Width           =   855
      End
   End
   Begin VB.Frame frmGeometry 
      Caption         =   "Geometry"
      Height          =   4215
      Left            =   120
      TabIndex        =   6
      Top             =   3720
      Width           =   3615
      Begin VB.CommandButton cmdClearGeometry 
         Caption         =   "Clear"
         Height          =   375
         Left            =   1680
         TabIndex        =   19
         Top             =   3720
         Width           =   855
      End
      Begin VB.TextBox txtGeomA 
         Height          =   1455
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   2
         TabIndex        =   9
         Top             =   480
         Width           =   3375
      End
      Begin VB.TextBox txtGeomB 
         Height          =   1335
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   2
         TabIndex        =   8
         Top             =   2280
         Width           =   3375
      End
      Begin VB.CommandButton cmdApplyGeometry 
         Caption         =   "Apply"
         Height          =   375
         Left            =   2640
         TabIndex        =   7
         Top             =   3720
         Width           =   855
      End
      Begin VB.Label lblWKTB 
         Caption         =   "B"
         Height          =   255
         Left            =   120
         TabIndex        =   11
         Top             =   2040
         Width           =   255
      End
      Begin VB.Label lblWKTA 
         Caption         =   "A"
         Height          =   255
         Left            =   120
         TabIndex        =   10
         Top             =   240
         Width           =   255
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' *** constant value ***
Private Const SHAPE_COORDSIZE = "500 500"
Private Const SHAPE_COORDORIGIN = "0 0"
Private Const PATH_POINTRADIUS = 4
Private Const STR_RESULT = "RESULT"
Private Const STR_INPUT = "INPUT"
Private Const STR_ERROR = "ERROR"
Private Const STR_NOTICE = "NOTICE"
Private Const STR_EXPECT = "EXPECT"

' *** member variable ***
Private WithEvents m_oGeos As Geos.API
Attribute m_oGeos.VB_VarHelpID = -1
Private m_hGeomA As Long
Private m_hGeomB As Long
Private m_hGeomResult As Long
Private m_oXML As Object
Private m_strArg1 As String
Private m_strArg2 As String
Private m_strArg3 As String

' *** geos event ***
Private Sub m_oGeos_onNotice(ByVal strNotice As String)
    writeResult STR_NOTICE, strNotice
End Sub

Private Sub m_oGeos_onError(ByVal strError As String)
    writeResult STR_ERROR, strError
End Sub

' *** vb form event ***
Private Sub Form_Initialize()
    Set m_oGeos = New Geos.API
    m_oGeos.init
End Sub

Private Sub Form_Terminate()
    If m_hGeomA <> 0 Then
        m_oGeos.Geom_destroy m_hGeomA
    End If
    If m_hGeomB <> 0 Then
        m_oGeos.Geom_destroy m_hGeomB
    End If
    If m_hGeomResult <> 0 Then
        m_oGeos.Geom_destroy m_hGeomResult
    End If
    m_oGeos.finish
    Set m_oGeos = Nothing
    Set m_oXML = Nothing
End Sub

Private Sub Form_Load()
    cmbOperation.Clear
    addOperation "Intersection", 2
    addOperation "Buffer", 1
    addOperation "ConvexHull", 1
    addOperation "Difference", 2
    addOperation "SymDifference", 2
    addOperation "Boundary", 1              ' op name "getboundary"
    addOperation "Union", 2
    addOperation "PointOnSurface", 1
    addOperation "GetCentroid", 1
    addOperation "Relate", 2
    addOperation "LineMerge", 1
    addOperation "RelatePattern", 2         ' op name "relate"
    addOperation "Disjoint", 2
    addOperation "Touches", 2
    addOperation "Intersects", 2
    addOperation "Crosses", 2
    addOperation "Within", 2
    addOperation "Contains", 2
    addOperation "Overlaps", 2
    addOperation "Equals", 2
    addOperation "isEmpty", 1
    addOperation "isValid", 1
    addOperation "isSimple", 1
    addOperation "isRing", 1
    addOperation "HasZ", 1
    addOperation "GeomTypeId", 1
    addOperation "GetSRID", 1
    addOperation "SetSRID", 1
    addOperation "GetNumGeometries", 1
    addOperation "GetGeometryN", 1
    addOperation "GetNumInteriorRings", 1
    addOperation "GetInteriorRingN", 1
    addOperation "GetExteriorRing", 1
    addOperation "GetNumCoordinates", 1
    addOperation "Distance", 2
    addOperation "Envelope", 1
    addOperation "GeomType", 1
    addOperation "Area", 1
    addOperation "Length", 1
    
    ctlCanvas.Navigate App.Path + "\canvas.html"
End Sub

Private Sub cmdApplyGeometry_Click()
    If m_hGeomA <> 0 Then
        m_oGeos.Geom_destroy m_hGeomA
        m_hGeomA = 0
    End If
    If m_hGeomB <> 0 Then
        m_oGeos.Geom_destroy m_hGeomB
        m_hGeomB = 0
    End If
    If txtGeomA.Text <> "" Then
        m_hGeomA = m_oGeos.GeomFromWKT(txtGeomA.Text)
    End If
    If txtGeomB.Text <> "" Then
        m_hGeomB = m_oGeos.GeomFromWKT(txtGeomB.Text)
    End If
    drawGeometry "GeomA", m_hGeomA
    drawGeometry "GeomB", m_hGeomB
End Sub

Private Sub cmdClearGeometry_Click()
    If m_hGeomA <> 0 Then
        m_oGeos.Geom_destroy m_hGeomA
        m_hGeomA = 0
    End If
    txtGeomA.Text = ""
    drawGeometry "GeomA", m_hGeomA
    If m_hGeomB <> 0 Then
        m_oGeos.Geom_destroy m_hGeomB
        m_hGeomB = 0
    End If
    txtGeomB.Text = ""
    drawGeometry "GeomB", m_hGeomB
End Sub

Private Sub cmbOperation_Click()
   ' base settings
    If m_strArg1 <> "" Then txtArg(0).Text = m_strArg1
    If m_strArg2 <> "" Then txtArg(1).Text = m_strArg2
    If m_strArg3 <> "" Then txtArg(2).Text = m_strArg3
    Select Case cmbOperation.ItemData(cmbOperation.ListIndex)
        Case 1
            setArgsVisible 1
            lblArg(0).Caption = "Geometry"
            If m_strArg1 = "" Then txtArg(0).Text = "A"
        Case 2
            setArgsVisible 2
            lblArg(0).Caption = "GeometryA"
            lblArg(1).Caption = "GeometryB"
            If m_strArg1 = "" Then txtArg(0).Text = "A"
            If m_strArg2 = "" Then txtArg(1).Text = "B"
    End Select

    ' additional settings
    Select Case cmbOperation.List(cmbOperation.ListIndex)
        Case "Buffer"
            setArgsVisible 3
            lblArg(1).Caption = "Width"
            lblArg(2).Caption = "QuadrantSegments"
            If m_strArg2 = "" Then txtArg(1).Text = "100"
            If m_strArg3 = "" Then txtArg(2).Text = "10"
        Case "RelatePattern"
            setArgsVisible 3
            lblArg(2).Caption = "Pattern"
            If m_strArg3 = "" Then txtArg(2).Text = "FFFFFFFFF"
        Case "SetSRID"
            setArgsVisible 2
            lblArg(1).Caption = "SRID"
            If m_strArg2 = "" Then txtArg(1).Text = "10"
        Case "GetGeometryN", _
                "GetInteriorRingN"
            setArgsVisible 2
            lblArg(1).Caption = "N"
            If m_strArg2 = "" Then txtArg(1).Text = "0"
    End Select
End Sub

Private Sub cmdClearOperation_Click()
    ' clear result
    If m_hGeomResult <> 0 Then
        m_oGeos.Geom_destroy m_hGeomResult
        m_hGeomResult = 0
    End If
    txtResult.Text = ""
    drawGeometry "GeomResult", m_hGeomResult
End Sub

Private Sub cmdExecOperation_Click()
    If cmbOperation.ListIndex = -1 Then
        Exit Sub
    End If

    ' check arguments
    Dim i As Integer
    For i = 0 To 2
        If txtArg(i).Visible = True And txtArg(i).Text = "" Then
            writeResult "INPUT", lblArg(i) + "is not specified."
            Exit Sub
        End If
    Next i

    ' clear result
    If m_hGeomResult <> 0 Then
        m_oGeos.Geom_destroy m_hGeomResult
        m_hGeomResult = 0
    End If
    txtResult.Text = ""
    
    ' set geometry handle
    Dim hGeom1 As Long
    Dim hGeom2 As Long
    Select Case cmbOperation.ItemData(cmbOperation.ListIndex)
        Case 1
            hGeom1 = getGeometry(txtArg(0).Text)
        Case 2
            hGeom1 = getGeometry(txtArg(0).Text)
            hGeom2 = getGeometry(txtArg(1).Text)
    End Select
    
    ' execute operation
    Dim nResult As Long
    Dim strResult As String
    Dim dVal As Double
    Dim nVal As Long
    Dim strVal As String
    Dim eType As GEOSGeomTypes

    Select Case cmbOperation.List(cmbOperation.ListIndex)
        Case "Intersection"
            m_hGeomResult = m_oGeos.Intersection(hGeom1, hGeom2)
            updateGeomResult
        Case "Buffer"
            dVal = CDbl(txtArg(1).Text)
            nVal = CLng(txtArg(2).Text)
            m_hGeomResult = m_oGeos.Buffer(hGeom1, dVal, nVal)
            updateGeomResult
        Case "ConvexHull"
            m_hGeomResult = m_oGeos.ConvexHull(hGeom1)
            updateGeomResult
        Case "Difference"
            m_hGeomResult = m_oGeos.Difference(hGeom1, hGeom2)
            updateGeomResult
        Case "SymDifference"
            m_hGeomResult = m_oGeos.SymDifference(hGeom1, hGeom2)
            updateGeomResult
        Case "Boundary"
            m_hGeomResult = m_oGeos.Boundary(hGeom1)
            updateGeomResult
        Case "Union"
            m_hGeomResult = m_oGeos.Union(hGeom1, hGeom2)
            updateGeomResult
        Case "PointOnSurface"
            m_hGeomResult = m_oGeos.PointOnSurface(hGeom1)
            updateGeomResult
        Case "GetCentroid"
            m_hGeomResult = m_oGeos.GetCentroid(hGeom1)
            updateGeomResult
        Case "Relate"
            strResult = m_oGeos.Relate(hGeom1, hGeom2)
            writeResult STR_RESULT, strResult
        Case "LineMerge"
            m_hGeomResult = m_oGeos.LineMerge(hGeom1)
            updateGeomResult
        Case "RelatePattern"
            strVal = txtArg(2).Text
            nResult = m_oGeos.RelatePattern(hGeom1, hGeom2, strVal)
            writeResult STR_RESULT, nResult
        Case "Disjoint"
            nResult = m_oGeos.Disjoint(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Touches"
            nResult = m_oGeos.Touches(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Intersects"
            nResult = m_oGeos.Intersects(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Crosses"
            nResult = m_oGeos.Crosses(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Within"
            nResult = m_oGeos.Within(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Contains"
            nResult = m_oGeos.Contains(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Overlaps"
            nResult = m_oGeos.Overlaps(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "Equals"
            nResult = m_oGeos.Equals(hGeom1, hGeom2)
            writeResult STR_RESULT, nResult
        Case "isEmpty"
            nResult = m_oGeos.IsEmpty(hGeom1)
            writeResult STR_RESULT, nResult
        Case "isValid"
            nResult = m_oGeos.isValid(hGeom1)
            writeResult STR_RESULT, nResult
        Case "isSimple"
            nResult = m_oGeos.isSimple(hGeom1)
            writeResult STR_RESULT, nResult
        Case "isRing"
            nResult = m_oGeos.isRing(hGeom1)
            writeResult STR_RESULT, nResult
        Case "HasZ"
            nResult = m_oGeos.HasZ(hGeom1)
            writeResult STR_RESULT, nResult
        Case "GeomTypeId"
            eType = m_oGeos.GeomTypeId(hGeom1)
            writeResult STR_RESULT, eType
        Case "GetSRID"
            nResult = m_oGeos.GetSRID(hGeom1)
            writeResult STR_RESULT, nResult
        Case "SetSRID"
            nVal = CLng(txtArg(1).Text)
            m_oGeos.SetSRID hGeom1, nVal
        Case "GetNumGeometries"
            nResult = m_oGeos.GetNumGeometries(hGeom1)
            writeResult STR_RESULT, nResult
        Case "GetGeometryN"
            nVal = CLng(txtArg(1).Text)
            nResult = m_oGeos.GetGeometryN(hGeom1, nVal)
            writeResult STR_RESULT, nResult
        Case "GetNumInteriorRings"
            nResult = m_oGeos.GetNumInteriorRings(hGeom1)
            writeResult STR_RESULT, nResult
        Case "GetInteriorRingN"
            nVal = CLng(txtArg(1).Text)
            nResult = m_oGeos.GetInteriorRingN(hGeom1, nVal)
            writeResult STR_RESULT, nResult
        Case "GetExteriorRing"
            m_hGeomResult = m_oGeos.GetExteriorRing(hGeom1)
            updateGeomResult
        Case "GetNumCoordinates"
            nResult = m_oGeos.GetNumCoordinates(hGeom1)
            writeResult STR_RESULT, nResult
        Case "Distance"
            nResult = m_oGeos.Distance(hGeom1, hGeom2, dVal)
            writeResult STR_RESULT, nResult
            writeResult "Distance", dVal
        Case "Envelope"
            m_hGeomResult = m_oGeos.Envelope(hGeom1)
            updateGeomResult
        Case "GeomType"
            strResult = m_oGeos.GeomType(hGeom1)
            writeResult STR_RESULT, strResult
        Case "Area"
            nResult = m_oGeos.Area(hGeom1, dVal)
            writeResult STR_RESULT, nResult
            writeResult "Area", dVal
        Case "Length"
            nResult = m_oGeos.Length(hGeom1, dVal)
            writeResult STR_RESULT, nResult
            writeResult "Length", dVal
    End Select
End Sub

Private Sub cmdLoadTestCase_Click()
    ' clear settings
    cmbTestCase.Clear
    If Not m_oXML Is Nothing Then
        ' close current xml file
        Set m_oXML = Nothing
    End If
    
    ' show dialog
    cdlTestCase.Filter = "Test Case File(*.xml)|*.xml"
    cdlTestCase.Flags = cdlOFNFileMustExist Or cdlOFNHideReadOnly
    cdlTestCase.InitDir = App.Path
    cdlTestCase.ShowOpen
    If cdlTestCase.FileName = "" Then
        Exit Sub
    End If

    ' load xml file
    Set m_oXML = CreateObject("Microsoft.XMLDOM")
    m_oXML.Load cdlTestCase.FileName
    
    ' add test case to combobox
    Dim oCases As Object
    Set oCases = m_oXML.getElementsbytagname("case")
    If oCases Is Nothing Then
        Exit Sub
    End If

    Dim oCase As Object
    For Each oCase In oCases
        Dim oNode As Object
        For Each oNode In oCase.childNodes
            If LCase(oNode.tagname) = "desc" Then
                cmbTestCase.AddItem oNode.Text
            End If
        Next
    Next
End Sub

Private Sub cmbTestCase_Click()
    ' clear geometry and operation
    cmdClearGeometry_Click
    cmdClearOperation_Click

    ' get target case
    Dim oCases As Object
    Set oCases = m_oXML.getElementsbytagname("case")
    If oCases Is Nothing Then
        Exit Sub
    End If
    Dim oTargetCase As Object
    Dim oCase As Object
    For Each oCase In oCases
        Dim oNode As Object
        For Each oNode In oCase.childNodes
            If LCase(oNode.tagname) = "desc" And oNode.Text = cmbTestCase.Text Then
                Set oTargetCase = oCase
                Exit For
            End If
        Next
        If Not oTargetCase Is Nothing Then
            Exit For
        End If
    Next
    If oTargetCase Is Nothing Then
        Exit Sub
    End If
    
    ' apply settings and execute
    Set oNode = Nothing
    Dim oTest As Object
    For Each oNode In oTargetCase.childNodes
        Select Case LCase(oNode.tagname)
            Case "a"
                txtGeomA.Text = oNode.Text
            Case "b"
                txtGeomB.Text = oNode.Text
            Case "test"
                Set oTest = oNode
        End Select
    Next
    If oTest Is Nothing Then
        Exit Sub
    End If
    
    Set oNode = Nothing
    Dim oOpe As Object
    For Each oNode In oTest.childNodes
        If LCase(oNode.tagname) = "op" Then
            Set oOpe = oNode
            Exit For
        End If
    Next
    If oOpe Is Nothing Then
        Exit Sub
    End If
    
    Dim strOpe As String
    Select Case LCase(oOpe.getAttribute("name"))
        Case "relate"
            strOpe = "relatepattern"
        Case "getboundary"
            strOpe = "boundary"
        Case Else
            strOpe = LCase(oOpe.getAttribute("name"))
    End Select

    If Not IsNull(oOpe.getAttribute("arg1")) Then
        m_strArg1 = oOpe.getAttribute("arg1")
    End If
    If Not IsNull(oOpe.getAttribute("arg2")) Then
        m_strArg2 = oOpe.getAttribute("arg2")
    End If
    If Not IsNull(oOpe.getAttribute("arg3")) Then
        m_strArg3 = oOpe.getAttribute("arg3")
    End If

    Dim i As Long
    Dim nCount As Long
    nCount = cmbOperation.ListCount
    For i = 0 To nCount - 1
        If strOpe = LCase(cmbOperation.List(i)) Then
            cmbOperation.ListIndex = i
            Exit For
        End If
    Next i

    cmdApplyGeometry_Click
    cmdExecOperation_Click

    Dim strExpect As String
    Select Case LCase(oOpe.Text)
        Case "true"
            strExpect = "1"
        Case "false"
            strExpect = "0"
        Case Else
            strExpect = oOpe.Text
    End Select
    writeResult STR_EXPECT, strExpect

    m_strArg1 = ""
    m_strArg2 = ""
    m_strArg3 = ""
End Sub

' *** helper function and procedure ***
Private Sub setArgsVisible(nArgCount As Integer)
    Dim i As Integer
    For i = 0 To 2
        lblArg(i).Visible = i < nArgCount
        txtArg(i).Visible = i < nArgCount
    Next i
End Sub

Private Sub addOperation(strOperation As String, nGeomCount As Integer)
    Dim nIndex As Integer
    nIndex = cmbOperation.ListCount
    cmbOperation.AddItem strOperation
    cmbOperation.ItemData(nIndex) = nGeomCount
End Sub

Private Function getGeometry(strGeom As String) As Long
    If UCase(strGeom) = "A" Then
        getGeometry = m_hGeomA
    ElseIf UCase(strGeom) = "B" Then
        getGeometry = m_hGeomB
    Else
        getGeometry = 0
    End If
    If getGeometry = 0 Then
        writeResult "INPUT", "Geometry" + strGeom + " is nothing."
    End If
End Function

Private Sub updateGeomResult()
    Dim strBuf As String
    If m_hGeomResult <> 0 Then
        strBuf = m_oGeos.GeomToWKT(m_hGeomResult)
    Else
        strBuf = "Nothing"
    End If
    writeResult STR_RESULT, strBuf
    drawGeometry "GeomResult", m_hGeomResult
End Sub

Private Sub writeResult(strName As String, vResult As Variant)
    If txtResult.Text <> "" Then
        txtResult.Text = txtResult.Text + vbCrLf
    End If
    txtResult.Text = txtResult.Text + strName + ":" + vbTab + CStr(vResult)
End Sub

Private Sub drawGeometry(strId As String, hGeom As Long)
    Dim oGroup As Object
    Dim oShape As Object
    Dim oPath As Object
    Dim oNode As Object

    Set oGroup = ctlCanvas.Document.getElementsbytagname("group")
    For Each oShape In oGroup(0).childNodes
        If oShape.Id = strId Then
            Exit For
        End If
    Next
    If oShape Is Nothing Then
        Exit Sub
    End If

    For Each oNode In oShape.childNodes
        If LCase(oNode.tagname) = "path" Then
            Set oPath = oNode
            Exit For
        End If
    Next
    If oPath Is Nothing Then
        Exit Sub
    End If

    If hGeom = 0 Then
        ' set null path
        oPath.setAttribute "v", "m 0 0 l e"
        Exit Sub
    End If

    oShape.setAttribute "coordsize", SHAPE_COORDSIZE
    oShape.setAttribute "coordorigin", SHAPE_COORDORIGIN
    oPath.setAttribute "v", CStr(getPath(hGeom))
End Sub

Private Function getPath(hGeom As Long) As String
On Error GoTo EXCEPTION ' for avoid overflow error
    Dim strPath As String
    Dim hCoordSeq As Long
    Dim nCoords As Long
    Dim hShell As Long
    Dim hHole As Long
    Dim nHoles As Long
    Dim hElem As Long
    Dim nElems As Long
    Dim dX As Double
    Dim dY As Double
    Dim nResult As Long
    Dim i As Long
    Dim j As Long
    Select Case m_oGeos.GeomTypeId(hGeom)
        Case GEOS_POINT
            nCoords = m_oGeos.GetNumCoordinates(hGeom)
            hCoordSeq = m_oGeos.Geom_getCoordSeq(hGeom)
            If nCoords > 0 Then
                nResult = m_oGeos.CoordSeq_getX(hCoordSeq, 0, dX)
                nResult = m_oGeos.CoordSeq_getY(hCoordSeq, 0, dY)
                strPath = strPath + "ar " + _
                            CStr(CLng(dX) - PATH_POINTRADIUS) + " " + _
                            CStr(CLng(dY) - PATH_POINTRADIUS) + " " + _
                            CStr(CLng(dX) + PATH_POINTRADIUS) + " " + _
                            CStr(CLng(dY) + PATH_POINTRADIUS) + " " + _
                            CStr(CLng(dX) + PATH_POINTRADIUS) + " " + _
                            CStr(CLng(dY)) + " " + _
                            CStr(CLng(dX) + PATH_POINTRADIUS) + " " + _
                            CStr(CLng(dY)) + " " + _
                            "e"
            End If
        Case GEOS_LINESTRING
            nCoords = m_oGeos.GetNumCoordinates(hGeom)
            hCoordSeq = m_oGeos.Geom_getCoordSeq(hGeom)
            If nCoords > 0 Then
                nResult = m_oGeos.CoordSeq_getX(hCoordSeq, 0, dX)
                nResult = m_oGeos.CoordSeq_getY(hCoordSeq, 0, dY)
                strPath = strPath + "m " + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " nf l "
                For i = 1 To nCoords - 1
                    nResult = m_oGeos.CoordSeq_getX(hCoordSeq, i, dX)
                    nResult = m_oGeos.CoordSeq_getY(hCoordSeq, i, dY)
                    strPath = strPath + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " "
                Next i
                strPath = strPath + "e"
            End If
        Case GEOS_LINEARRING
            nCoords = m_oGeos.GetNumCoordinates(hGeom)
            hCoordSeq = m_oGeos.Geom_getCoordSeq(hGeom)
            If nCoords > 0 Then
                nResult = m_oGeos.CoordSeq_getX(hCoordSeq, 0, dX)
                nResult = m_oGeos.CoordSeq_getY(hCoordSeq, 0, dY)
                strPath = strPath + "m " + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " l "
                For i = 1 To nCoords - 1
                    nResult = m_oGeos.CoordSeq_getX(hCoordSeq, i, dX)
                    nResult = m_oGeos.CoordSeq_getY(hCoordSeq, i, dY)
                    strPath = strPath + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " "
                Next i
                strPath = strPath + "e"
            End If
        Case GEOS_POLYGON
            hShell = m_oGeos.GetExteriorRing(hGeom)
            nCoords = m_oGeos.GetNumCoordinates(hShell)
            hCoordSeq = m_oGeos.Geom_getCoordSeq(hShell)
            If nCoords > 0 Then
                nResult = m_oGeos.CoordSeq_getX(hCoordSeq, 0, dX)
                nResult = m_oGeos.CoordSeq_getY(hCoordSeq, 0, dY)
                strPath = strPath + "m " + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " l "
                For i = 1 To nCoords - 1
                    nResult = m_oGeos.CoordSeq_getX(hCoordSeq, i, dX)
                    nResult = m_oGeos.CoordSeq_getY(hCoordSeq, i, dY)
                    strPath = strPath + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " "
                Next i
                strPath = strPath + "e"
            End If
            nHoles = m_oGeos.GetNumInteriorRings(hGeom)
            For j = 0 To nHoles - 1
                hHole = m_oGeos.GetInteriorRingN(hGeom, j)
                nCoords = m_oGeos.GetNumCoordinates(hHole)
                hCoordSeq = m_oGeos.Geom_getCoordSeq(hHole)
                If nCoords > 0 Then
                    nResult = m_oGeos.CoordSeq_getX(hCoordSeq, 0, dX)
                    nResult = m_oGeos.CoordSeq_getY(hCoordSeq, 0, dY)
                    strPath = strPath + " m " + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " nf l "
                    For i = 1 To nCoords - 1
                        nResult = m_oGeos.CoordSeq_getX(hCoordSeq, i, dX)
                        nResult = m_oGeos.CoordSeq_getY(hCoordSeq, i, dY)
                        strPath = strPath + CStr(CLng(dX)) + " " + CStr(CLng(dY)) + " "
                    Next i
                    strPath = strPath + "e"
                End If
            Next j
        Case GEOS_MULTIPOINT, GEOS_MULTILINESTRING, GEOS_MULTIPOLYGON, GEOS_GEOMETRYCOLLECTION
            nElems = m_oGeos.GetNumGeometries(hGeom)
            If nElems > 0 Then
                For i = 0 To nElems - 1
                    hElem = m_oGeos.GetGeometryN(hGeom, i)
                    strPath = strPath + getPath(hElem) + " "
                Next i
            End If
    End Select
    getPath = strPath
    Exit Function
EXCEPTION:
    MsgBox "Exception occurred at getPath." + vbCrLf + _
            "Description:" + Err.Description + vbCrLf + _
            "Number:" + CStr(Err.Number)
    getPath = ""
End Function
