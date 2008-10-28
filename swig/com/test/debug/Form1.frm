VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   10680
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6315
   LinkTopic       =   "Form1"
   ScaleHeight     =   10680
   ScaleWidth      =   6315
   StartUpPosition =   3  'Windows ‚ÌŠù’è’l
   Begin VB.CommandButton cmdcreatePoint 
      Caption         =   "createPoint"
      Height          =   375
      Left            =   2880
      TabIndex        =   23
      Top             =   600
      Width           =   2655
   End
   Begin VB.CommandButton cmdCoordinateSequence 
      Caption         =   "CoordinateSequence"
      Height          =   375
      Left            =   2880
      TabIndex        =   22
      Top             =   120
      Width           =   2655
   End
   Begin VB.CommandButton cmdversion 
      Caption         =   "version"
      Height          =   375
      Left            =   120
      TabIndex        =   21
      Top             =   10200
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_WKB_NDR 
      Caption         =   "GEOS_WKB_NDR"
      Height          =   375
      Left            =   120
      TabIndex        =   20
      Top             =   9720
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_WKB_XDR 
      Caption         =   "GEOS_WKB_XDR"
      Height          =   375
      Left            =   120
      TabIndex        =   19
      Top             =   9240
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_GEOMETRYCOLLECTION 
      Caption         =   "GEOS_GEOMETRYCOLLECTION"
      Height          =   375
      Left            =   120
      TabIndex        =   18
      Top             =   8760
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_MULTIPOLYGON 
      Caption         =   "GEOS_MULTIPOLYGON"
      Height          =   375
      Left            =   120
      TabIndex        =   17
      Top             =   8280
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_MULTILINESTRING 
      Caption         =   "GEOS_MULTILINESTRING"
      Height          =   375
      Left            =   120
      TabIndex        =   16
      Top             =   7800
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_MULTIPOINT 
      Caption         =   "GEOS_MULTIPOINT"
      Height          =   375
      Left            =   120
      TabIndex        =   15
      Top             =   7320
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_POLYGON 
      Caption         =   "GEOS_POLYGON"
      Height          =   375
      Left            =   120
      TabIndex        =   14
      Top             =   6840
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_LINEARRING 
      Caption         =   "GEOS_LINEARRING"
      Height          =   375
      Left            =   120
      TabIndex        =   13
      Top             =   6360
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_LINESTRING 
      Caption         =   "GEOS_LINESTRING"
      Height          =   375
      Left            =   120
      TabIndex        =   12
      Top             =   5880
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_POINT 
      Caption         =   "GEOS_POINT"
      Height          =   375
      Left            =   120
      TabIndex        =   11
      Top             =   5400
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_CAPI_VERSION 
      Caption         =   "GEOS_CAPI_VERSION"
      Height          =   375
      Left            =   120
      TabIndex        =   10
      Top             =   4920
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_CAPI_LAST_INTERFACE 
      Caption         =   "GEOS_CAPI_LAST_INTERFACE"
      Height          =   375
      Left            =   120
      TabIndex        =   9
      Top             =   4440
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_CAPI_FIRST_INTERFACE 
      Caption         =   "GEOS_CAPI_FIRST_INTERFACE"
      Height          =   375
      Left            =   120
      TabIndex        =   8
      Top             =   3960
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_CAPI_VERSION_PATCH 
      Caption         =   "GEOS_CAPI_VERSION_PATCH"
      Height          =   375
      Left            =   120
      TabIndex        =   7
      Top             =   3480
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_CAPI_VERSION_MINOR 
      Caption         =   "GEOS_CAPI_VERSION_MINOR"
      Height          =   375
      Left            =   120
      TabIndex        =   6
      Top             =   3000
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_CAPI_VERSION_MAJOR 
      Caption         =   "GEOS_CAPI_VERSION_MAJOR"
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   2520
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_JTS_PORT 
      Caption         =   "GEOS_JTS_PORT"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   2040
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_VERSION 
      Caption         =   "GEOS_VERSION"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   1560
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_VERSION_PATCH 
      Caption         =   "GEOS_VERSION_PATCH"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   1080
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_VERSION_MINOR 
      Caption         =   "GEOS_VERSION_MINOR"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   2655
   End
   Begin VB.CommandButton cmdGEOS_VERSION_MAJOR 
      Caption         =   "GEOS_VERSION_MAJOR"
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdCoordinateSequence_Click()
    Dim geos As New geos
    Dim cs As geosTLB.ICoordinateSequence
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
    If cs Is Nothing Then
        MsgBox "Failed"
    Else
        Call cs.setX(0, 100)
        Call cs.setY(0, 100)
        MsgBox "Succeeded"
    End If
End Sub

Private Sub cmdcreatePoint_Click()
    Dim geos As New geos
    Dim cs As geosTLB.ICoordinateSequence
    Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
    Call cs.setX(0, 100)
    Call cs.setY(0, 100)
    Dim point As geosTLB.IGeometry
    Set point = geos.createPoint(cs)
    MsgBox "Geometry type:" + point.geomType
End Sub

Private Sub cmdGEOS_CAPI_FIRST_INTERFACE_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_CAPI_FIRST_INTERFACE)
End Sub

Private Sub cmdGEOS_CAPI_LAST_INTERFACE_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_CAPI_LAST_INTERFACE)
End Sub

Private Sub cmdGEOS_CAPI_VERSION_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_CAPI_VERSION)
End Sub

Private Sub cmdGEOS_CAPI_VERSION_MAJOR_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_CAPI_VERSION_MAJOR)
End Sub

Private Sub cmdGEOS_CAPI_VERSION_MINOR_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_CAPI_VERSION_MINOR)
End Sub

Private Sub cmdGEOS_CAPI_VERSION_PATCH_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_CAPI_VERSION_PATCH)
End Sub

Private Sub cmdGEOS_GEOMETRYCOLLECTION_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_GEOMETRYCOLLECTION)
End Sub

Private Sub cmdGEOS_JTS_PORT_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_JTS_PORT)
End Sub

Private Sub cmdGEOS_LINEARRING_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_LINEARRING)
End Sub

Private Sub cmdGEOS_LINESTRING_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_LINESTRING)
End Sub

Private Sub cmdGEOS_MULTILINESTRING_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_MULTILINESTRING)
End Sub

Private Sub cmdGEOS_MULTIPOINT_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_MULTIPOINT)
End Sub

Private Sub cmdGEOS_MULTIPOLYGON_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_MULTIPOLYGON)
End Sub

Private Sub cmdGEOS_POINT_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_POINT)
End Sub

Private Sub cmdGEOS_POLYGON_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_POLYGON)
End Sub

Private Sub cmdGEOS_VERSION_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_VERSION)
End Sub

Private Sub cmdGEOS_VERSION_MAJOR_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_VERSION_MAJOR)
End Sub

Private Sub cmdGEOS_VERSION_MINOR_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_VERSION_MINOR)
End Sub

Private Sub cmdGEOS_VERSION_PATCH_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_VERSION_PATCH)
End Sub

Private Sub cmdGEOS_WKB_NDR_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_WKB_NDR)
End Sub

Private Sub cmdGEOS_WKB_XDR_Click()
    Dim geos As New geos
    MsgBox CStr(geos.GEOS_WKB_XDR)
End Sub

Private Sub cmdversion_Click()
    Dim geos As New geos
    MsgBox CStr(geos.version)
End Sub
