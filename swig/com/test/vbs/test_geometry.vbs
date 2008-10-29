Option Explicit

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
		WScript.Echo "assertEqual: " & message
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

Class TestGeometry
	Sub testCreatePoint()
		WScript.Echo "testCreatePoint"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3)
		cs.setX 0, 7
		cs.setY 0, 8
		cs.setZ 0, 9
		
		Dim geom
		Set geom = geos.createPoint(cs)
		assert (Not geom Is Nothing), "geom" ' TODO:
		assertEqual "Point", geom.geomType, "geom.geomType"
		assertEqual geos.GEOS_POINT, geom.typeId, "geom.typeId"
		
		assertEqual False, geom.isEmpty, "geom.isEmpty"
		assertEqual True, geom.isValid, "geom.isValid"
		assertEqual True, geom.isSimple, "geom.isSimple"
		assertEqual False, geom.isRing, "geom.isRing"
		assertEqual True, geom.hasZ, "geom.hasZ"
		
		assertEqual 1, geom.getNumGeometries, "geom.getNumGeometries"
		
		Dim coords
		Set coords = geom.getCoordSeq
		assert (Not coords Is Nothing), "coords" ' TODO:
		assertEqual 7, coords.getX(0), "coords.getX(0)"
		assertEqual 8, coords.getY(0), "coords.getY(0)"
		assertEqual 9, coords.getZ(0), "coords.getZ(0)"
		
		assertEqual 0, geom.area, "geom.area"
		assertEqual 0, geom.length, "geom.length"
		
		report
	End Sub

	Sub testCreatePointIllegal()
		WScript.Echo "testCreatePointIllegal"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(0, 0)
		Dim geom
		Set geom = geos.createPoint(cs)
		
		report
	End Sub

	Sub testCreateLineString()
		WScript.Echo "testCreateLineString"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3)
		cs.setX 0, 7
		cs.setY 0, 8
		cs.setZ 0, 9
		cs.setX 1, 3
		cs.setY 1, 3
		cs.setZ 1, 3
		
		Dim geom
		Set geom = geos.createLineString(cs)
		assert (Not geom Is Nothing), "geom" ' TODO:
		assertEqual "LineString", geom.geomType, "geom.geomType"
		assertEqual geos.GEOS_LINESTRING, geom.typeId, "geom.typeId"
		
		assertEqual False, geom.isEmpty, "geom.isEmpty"
		assertEqual True, geom.isValid, "geom.isValid"
		assertEqual True, geom.isSimple, "geom.isSimple"
		assertEqual False, geom.isRing, "geom.isRing"
		assertEqual True, geom.hasZ, "geom.hasZ"
		
		assertEqual 1, geom.getNumGeometries, "geom.getNumGeometries"
		
		Dim coords
		Set coords = geom.getCoordSeq
		assert (Not coords Is Nothing), "coords" ' TODO:
		assertEqual 7, coords.getX(0), "coords.getX(0)"
		assertEqual 8, coords.getY(0), "coords.getY(0)"
		assertEqual 9, coords.getZ(0), "coords.getZ(0)"
		assertEqual 3, coords.getX(1), "coords.getX(1)"
		assertEqual 3, coords.getY(1), "coords.getY(1)"
		assertEqual 3, coords.getZ(1), "coords.getZ(1)"
		
		assertEqual 0, geom.area, "geom.area"
		assertEqual 6.4031242374328485, geom.length, "geom.length"
		
		report
	End Sub

	Sub testCreateLineStringIllegal()
		WScript.Echo "testCreateLineStringIllegal"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 0)
		Dim geom
		Set geom = geos.createLineString(cs)
		
		report
	End Sub

	Sub testCreateLinearRing()
		WScript.Echo "testCreateLinearRing"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(4, 3)
		cs.setX 0, 7
		cs.setY 0, 8
		cs.setZ 0, 9
		cs.setX 1, 3
		cs.setY 1, 3
		cs.setZ 1, 3
		cs.setX 2, 11
		cs.setY 2, 15.2
		cs.setZ 2, 2
		cs.setX 3, 7
		cs.setY 3, 8
		cs.setZ 3, 9
		
		Dim geom
		Set geom = geos.createLinearRing(cs)
		assert (Not geom Is Nothing), "geom" ' TODO:
		assertEqual "LinearRing", geom.geomType, "geom.geomType"
		assertEqual geos.GEOS_LINEARRING, geom.typeId, "geom.typeId"
		
		assertEqual False, geom.isEmpty, "geom.isEmpty"
		assertEqual True, geom.isValid, "geom.isValid"
		assertEqual True, geom.isSimple, "geom.isSimple"
		assertEqual True, geom.isRing, "geom.isRing"
		assertEqual True, geom.hasZ, "geom.hasZ"
		
		assertEqual 1, geom.getNumGeometries, "geom.getNumGeometries"
		
		Dim coords
		Set coords = geom.getCoordSeq
		assert (Not coords Is Nothing), "coords" ' TODO:
		assertEqual 7, coords.getX(0), "coords.getX(0)"
		assertEqual 8, coords.getY(0), "coords.getY(0)"
		assertEqual 9, coords.getZ(0), "coords.getZ(0)"
		assertEqual 3, coords.getX(1), "coords.getX(1)"
		assertEqual 3, coords.getY(1), "coords.getY(1)"
		assertEqual 3, coords.getZ(1), "coords.getZ(1)"
		assertEqual 11, coords.getX(2), "coords.getX(2)"
		assertEqual 15.2, coords.getY(2), "coords.getY(2)"
		assertEqual 2, coords.getZ(2), "coords.getZ(2)"
		assertEqual 7, coords.getX(3), "coords.getX(3)"
		assertEqual 8, coords.getY(3), "coords.getY(3)"
		assertEqual 9, coords.getZ(3), "coords.getZ(3)"
		
		assertEqual 0, geom.area, "geom.area"
		assertEqual 29.228665330091953, geom.length, "geom.length"
		
		report
	End Sub

	Sub testCreateLinearRingIllegal()
		WScript.Echo "testCreateLinearRingIllegal"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 0)
		Dim geom
		Set geom = geos.createLinearRing(cs)
		
		report
	End Sub

	Sub testCreatePolygon()
		WScript.Echo "testCreatePolygon"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(5, 2)
		cs.setX 0, 0
		cs.setY 0, 0
		
		cs.setX 1, 0
		cs.setY 1, 10
		
		cs.setX 2, 10
		cs.setY 2, 10
		
		cs.setX 3, 10
		cs.setY 3, 0
		
		cs.setX 4, 0
		cs.setY 4, 0
		Dim shell
		Set shell = geos.createLinearRing(cs)
		
		Dim geom
		Set geom = geos.createPolygon(shell, Nothing) ' TODO:
		assert (Not geom Is Nothing), "geom" ' TODO:
		assertEqual "Polygon", geom.geomType, "geom.geomType"
		assertEqual geos.GEOS_POLYGON, geom.typeId, "geom.typeId"
		
		assertEqual False, geom.isEmpty, "geom.isEmpty"
		assertEqual True, geom.isValid, "geom.isValid"
		assertEqual True, geom.isSimple, "geom.isSimple"
		assertEqual False, geom.isRing, "geom.isRing"
		assertEqual True, geom.hasZ, "geom.hasZ"
		
		assertEqual 1, geom.getNumGeometries, "geom.getNumGeometries"
		
		Dim exteriorRing
		Set exteriorRing = geom.getExteriorRing
		'assert (shell = exteriorRing), "exteriorRing" ' TODO:
		assertEqual 0, geom.getNumInteriorRings, "geom.getNumInteriorRings"
		
		'assert geom.getInteriorRingN(1) ' TODO:
		
		assertEqual 100, geom.area, "geom.area"
		assertEqual 40, geom.length, "geom.length"
		
		report
	End Sub

	Sub testCreatePolygonWithHoles()
		WScript.Echo "testCreatePolygonWithHoles"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		' Polygon shell
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(5, 2)
		cs.setX 0, 0
		cs.setY 0, 0
		
		cs.setX 1, 0
		cs.setY 1, 10
		
		cs.setX 2, 10
		cs.setY 2, 10
		
		cs.setX 3, 10
		cs.setY 3, 0
		
		cs.setX 4, 0
		cs.setY 4, 0
		Dim shell
		Set shell = geos.createLinearRing(cs)
		
		' Hole 1
		Dim cs1
		Set cs1 = geos.CoordinateSequence.new_CoordinateSequence(5, 2)
		cs1.setX 0, 2
		cs1.setY 0, 2
		
		cs1.setX 1, 2
		cs1.setY 1, 4
		
		cs1.setX 2, 4
		cs1.setY 2, 4
		
		cs1.setX 3, 4
		cs1.setY 3, 2
		
		cs1.setX 4, 2
		cs1.setY 4, 2
		Dim hole1
		Set hole1 = geos.createLinearRing(cs1)
		
		' Hole 2
		Dim cs2
		Set cs2 = geos.CoordinateSequence.new_CoordinateSequence(5, 2)
		cs2.setX 0, 6
		cs2.setY 0, 6
		
		cs2.setX 1, 6
		cs2.setY 1, 8
		
		cs2.setX 2, 8
		cs2.setY 2, 8
		
		cs2.setX 3, 8
		cs2.setY 3, 6
		
		cs2.setX 4, 6
		cs2.setY 4, 6
		Dim hole2
		Set hole2 = geos.createLinearRing(cs2)
		
'		Dim holes()
'		ReDim Preserve holes(2)
'		Set holes(0) = hole1
'		Set holes(1) = hole2
		
		Dim geom
		Set geom = geos.createPolygon(shell, Array(hole1, hole2))
		assert (Not geom Is Nothing), "geom" ' TODO:
		assertEqual "Polygon", geom.geomType, "geom.geomType"
		assertEqual geos.GEOS_POLYGON, geom.typeId, "geom.typeId"
		
		assertEqual False, geom.isEmpty, "geom.isEmpty"
		assertEqual True, geom.isValid, "geom.isValid"
		assertEqual True, geom.isSimple, "geom.isSimple"
		assertEqual False, geom.isRing, "geom.isRing"
		assertEqual True, geom.hasZ, "geom.hasZ"
		
		assertEqual 1, geom.getNumGeometries, "geom.getNumGeometries"
		
		Dim exteriorRing
		Set exteriorRing = geom.getExteriorRing
		'assert (shell = exteriorRing), "exteriorRing" ' TODO:
		
		assertEqual 2, geom.getNumInteriorRings, "geom.getNumInteriorRings"
		'assert (hole1 = geom.getInteriorRingN(0)) ' TODO:
		'assert (hole2 = geom.getInteriorRingN(1)) ' TODO:
		
		assertEqual 92, geom.area, "geom.area"
		assertEqual 56, geom.length, "geom.length"
		
		report
	End Sub

	Sub testDistance()
		WScript.Echo "testDistance"
		Dim geos
		Set geos = WScript.CreateObject("geos.geos")
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
		cs.setX 0, 0
		cs.setY 0, 0
		Dim geom1
		Set geom1 = geos.createPoint(cs)
		
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
		cs.setX 0, 3
		cs.setY 0, 4
		Dim geom2
		Set geom2 = geos.createPoint(cs)
		
		assertEqual 5, geom1.distance(geom2), "geom1.distance(geom2)"
		
		report
	End Sub
End Class

Dim test
Set test = new TestGeometry
test.testCreatePoint
'test.testCreatePointIllegal ' TODO:
test.testCreateLineString
'test.testCreateLineStringIllegal ' TODO:
test.testCreateLinearRing
'test.testCreateLinearRingIllegal ' TODO:
test.testCreatePolygon
test.testCreatePolygonWithHoles
test.testDistance
