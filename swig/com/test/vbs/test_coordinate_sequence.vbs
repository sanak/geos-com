Option Explicit

Dim geos
Set geos = WScript.CreateObject("geos.geos")

Dim results
results = ""

Sub assert(result, message)
	If result = False Then
		WScript.Echo "assert: " & message
		results = results & "x"
	Else
		results = results & "o"
	End If
End Sub

Sub assertEqual(expected, result, message)
	If expected <> result Then
		WScript.Echo "assertEqual: " & message & vbCrLf & "expected:" & vbTab & CStr(expected) & vbCrLf & "result:" & vbTab & CStr(result)
		results = results & "x"
	Else
		results = results & "o"
	End If
End Sub

Sub report()
	If InStr(1, results, "x") > 0 Then
		WScript.Echo "Failed! - " & results
	Else
		WScript.Echo "Succeeded! - " & results
	End If
	results = ""
End Sub

Class TestCoordinateSequence
	Sub testCreate()
		WScript.Echo "testCreate"
		
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
		assertEqual "ICoordinateSequence", TypeName(cs), "TypeName(cs)"
		
		report
	End Sub
	
	Sub testSize()
		WScript.Echo "testSize"
		
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(7, 2)
		assertEqual 7, cs.getSize, "cs.getSize"
		
		report
	End Sub
	
	Sub testGetterSetter()
		WScript.Echo "testGetterSetter"
		
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
		
		report
	End Sub
	
	Sub testIndexOutOfBounds()
		WScript.Echo "testIndexOutOfBounds"
		
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3)
		cs.setX 2, 6
		cs.setY 2, 6
		cs.setZ 2, 6
		
		report
	End Sub
	
	Sub testOrdinate()
		WScript.Echo "testOrdinate"
		
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
		cs.setOrdinate 0, 0, 2
		cs.setOrdinate 0, 1, 3
		cs.setOrdinate 0, 2, 4
		
		assertEqual 2, cs.getOrdinate(0, 0), "cs.getOrdinate(0, 0)"
		assertEqual 3, cs.getOrdinate(0, 1), "cs.getOrdinate(0, 1)"
		assertEqual 4, cs.getOrdinate(0, 2), "cs.getOrdinate(0, 2)"
		
		report
	End Sub
	
	Sub testClone()
		WScript.Echo "testClone"
		
		Dim cs1
		Set cs1 = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
		cs1.setX 0, 2
		cs1.setY 0, 3
		cs1.setZ 0, 4
		
		Dim cs2
		Set cs2 = cs1.clone
		
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
		
		report
	End Sub
	
	Sub testDimensions()
		WScript.Echo "testDimensions"
		
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
		assertEqual 3, cs.getDimensions, "cs.getDimensions"
		
		report
	End Sub
End Class

Dim test
Set test = new TestCoordinateSequence
test.testCreate
test.testSize
test.testGetterSetter
'test.testIndexOutOfBounds
test.testOrdinate
test.testClone
test.testDimensions
