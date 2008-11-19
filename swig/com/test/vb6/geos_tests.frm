VERSION 5.00
Begin VB.Form GeosTestsForm 
   BorderStyle     =   1
   Caption         =   "geos_tests"
   ClientHeight    =   4920
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6240
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   4920
   ScaleWidth      =   6240
   StartUpPosition =   3
   Begin VB.TextBox txtReport 
      Height          =   4215
      Left            =   2040
      MultiLine       =   -1  'True
      TabIndex        =   10
      Top             =   120
      Width           =   4095
   End
   Begin VB.CommandButton cmdExit 
      Caption         =   "exit"
      Height          =   375
      Left            =   4320
      TabIndex        =   9
      Top             =   4440
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
End
Attribute VB_Name = "GeosTestsForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub clearReport()
    GeosTestsForm.txtReport.Text = ""
    GeosTestsForm.txtReport.Refresh
End Sub

Private Sub cmdCombinations_Click()
    clearReport
    Dim test
    Set test = New TestGeosCombinations
End Sub

Private Sub cmdCoordinateSequence_Click()
    clearReport
    Dim test
    Set test = New TestCoordinateSequence
End Sub

Private Sub cmdExit_Click()
    End
End Sub

Private Sub cmdGeometry_Click()
    clearReport
    Dim test
    Set test = New TestGeometry
End Sub

Private Sub cmdIo_Click()
    clearReport
    Dim test
    Set test = New TestIo
End Sub

Private Sub cmdOperations_Click()
    clearReport
    Dim test
    Set test = New TestGeosOperations
End Sub

Private Sub cmdRelations_Click()
    clearReport
    Dim test
    Set test = New TestGeosRelations
End Sub

Private Sub cmdSrid_Click()
    clearReport
    Dim test
    Set test = New SridTest
End Sub

Private Sub cmdVersion_Click()
    clearReport
    Dim test
    Set test = New TestVersion
End Sub
