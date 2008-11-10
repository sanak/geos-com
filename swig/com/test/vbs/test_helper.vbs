Option Explicit

Dim geos
Set geos = WScript.CreateObject("geos.geos")

class GeosTestHelper
	Function createPoint(x, y)
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
		cs.setX 0, x
		cs.setY 0, y
		Set createPoint = geos.createPoint(cs)
	End Function
	
	Function createUshapedLineString(xoffset, yoffset, side)
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(4, 2)
		cs.setX 0, xoffset
		cs.setY 0, yoffset
		cs.setX 1, xoffset
		cs.setY 1, yoffset + side
		cs.setX 2, xoffset + side
		cs.setY 2, yoffset + side
		cs.setX 3, xoffset + side
		cs.setY 3, yoffset
		Set createUshapedLineString = geos.createLineString(cs)
	End Function
	
	' This function will create a LinearRing geometry
	' representing a square with the given origin and side 
	Function createSquareLinearRing(xoffset, yoffset, side)
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(5, 2)
		cs.setX 0, xoffset
		cs.setY 0, yoffset
		cs.setX 1, xoffset
		cs.setY 1, yoffset + side
		cs.setX 2, xoffset + side
		cs.setY 2, yoffset + side
		cs.setX 3, xoffset + side
		cs.setY 3, yoffset
		cs.setX 4, xoffset
		cs.setY 4, yoffset
		Set createSquareLinearRing = geos.createLinearRing(cs)
	End Function
	
	' This function will create a Polygon
	' geometry representing a square with the given origin 
	' and side and with a central hole 1/3 sided.
	Function createSquarePolygon(xoffset, yoffset, side)
		' We need a LinearRing for the polygon shell 
		Dim outer
		Set outer = createSquareLinearRing(xoffset, yoffset, side)
		
		' And another for the hole 
		Dim inner
		Set inner = createSquareLinearRing(xoffset + (side / 3), yoffset + (side / 3), (side / 3))
		
		Set createSquarePolygon = geos.createPolygon(outer, Array(inner))
	End Function
	
	Function createSimpleCollection(geoms)
		Dim wkt
		wkt = "GEOMETRYCOLLECTION (POLYGON ((0.00 250.00, 0.00 550.00, 300.00 550.00, 300.00 250.00, 0.00 250.00), (100.00 350.00, 200.00 350.00, 200.00 450.00, 100.00 450.00, 100.00 350.00)), POLYGON ((0.00 200.00, 0.00 500.00, 300.00 500.00, 300.00 200.00, 0.00 200.00), (100.00 300.00, 200.00 300.00, 200.00 400.00, 100.00 400.00, 100.00 300.00)), LINEARRING (0.00 0.00, 0.00 100.00, 100.00 100.00, 100.00 0.00, 0.00 0.00), LINEARRING (0.00 0.00, 0.00 100.00, 100.00 100.00, 100.00 0.00, 0.00 0.00), LINESTRING (60.00 60.00, 60.00 160.00, 160.00 160.00, 160.00 60.00), POINT (150.00 350.00))"
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Set createSimpleCollection = reader.read(wkt)
	End Function
	
	Function createCircle(centerX, centerY, radius)
		Dim wkt
		wkt = "POLYGON ((-5.00 0.00, -4.99 0.31, -4.96 0.63, -4.91 0.94, -4.84 1.24, -4.76 1.55, -4.65 1.84, -4.52 2.13, -4.38 2.41, -4.22 2.68, -4.05 2.94, -3.85 3.19, -3.64 3.42, -3.42 3.64, -3.19 3.85, -2.94 4.05, -2.68 4.22, -2.41 4.38, -2.13 4.52, -1.84 4.65, -1.55 4.76, -1.24 4.84, -0.94 4.91, -0.63 4.96, -0.31 4.99, 0.00 5.00, 0.31 4.99, 0.63 4.96, 0.94 4.91, 1.24 4.84, 1.55 4.76, 1.84 4.65, 2.13 4.52, 2.41 4.38, 2.68 4.22, 2.94 4.05, 3.19 3.85, 3.42 3.64, 3.64 3.42, 3.85 3.19, 4.05 2.94, 4.22 2.68, 4.38 2.41, 4.52 2.13, 4.65 1.84, 4.76 1.55, 4.84 1.24, 4.91 0.94, 4.96 0.63, 4.99 0.31, 5.00 0.00, 4.99 -0.31, 4.96 -0.63, 4.91 -0.94, 4.84 -1.24, 4.76 -1.55, 4.65 -1.84, 4.52 -2.13, 4.38 -2.41, 4.22 -2.68, 4.05 -2.94, 3.85 -3.19, 3.64 -3.42, 3.42 -3.64, 3.19 -3.85, 2.94 -4.05, 2.68 -4.22, 2.41 -4.38, 2.13 -4.52, 1.84 -4.65, 1.55 -4.76, 1.24 -4.84, 0.94 -4.91, 0.63 -4.96, 0.31 -4.99, -0.00 -5.00, -0.31 -4.99, -0.63 -4.96, -0.94 -4.91, -1.24 -4.84, -1.55 -4.76, -1.84 -4.65, -2.13 -4.52, -2.41 -4.38, -2.68 -4.22, -2.94 -4.05, -3.19 -3.85, -3.42 -3.64, -3.64 -3.42, -3.85 -3.19, -4.05 -2.94, -4.22 -2.68, -4.38 -2.41, -4.52 -2.13, -4.65 -1.84, -4.76 -1.55, -4.84 -1.24, -4.91 -0.94, -4.96 -0.63, -4.99 -0.31, -5.00 0.00))"
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Set createCircle = reader.read(wkt)
	End Function
	
	Function createEllipse(centerX, centerY, width, height)
		Dim wkt
		wkt = "POLYGON ((-4.00 0.00, -3.99 0.38, -3.97 0.75, -3.93 1.12, -3.87 1.49, -3.80 1.85, -3.72 2.21, -3.62 2.55, -3.51 2.89, -3.38 3.21, -3.24 3.53, -3.08 3.82, -2.92 4.11, -2.74 4.37, -2.55 4.62, -2.35 4.85, -2.14 5.07, -1.93 5.26, -1.70 5.43, -1.47 5.58, -1.24 5.71, -0.99 5.81, -0.75 5.89, -0.50 5.95, -0.25 5.99, 0.00 6.00, 0.25 5.99, 0.50 5.95, 0.75 5.89, 0.99 5.81, 1.24 5.71, 1.47 5.58, 1.70 5.43, 1.93 5.26, 2.14 5.07, 2.35 4.85, 2.55 4.62, 2.74 4.37, 2.92 4.11, 3.08 3.82, 3.24 3.53, 3.38 3.21, 3.51 2.89, 3.62 2.55, 3.72 2.21, 3.80 1.85, 3.87 1.49, 3.93 1.12, 3.97 0.75, 3.99 0.38, 4.00 0.00, 3.99 -0.38, 3.97 -0.75, 3.93 -1.12, 3.87 -1.49, 3.80 -1.85, 3.72 -2.21, 3.62 -2.55, 3.51 -2.89, 3.38 -3.21, 3.24 -3.53, 3.08 -3.82, 2.92 -4.11, 2.74 -4.37, 2.55 -4.62, 2.35 -4.85, 2.14 -5.07, 1.93 -5.26, 1.70 -5.43, 1.47 -5.58, 1.24 -5.71, 0.99 -5.81, 0.75 -5.89, 0.50 -5.95, 0.25 -5.99, -0.00 -6.00, -0.25 -5.99, -0.50 -5.95, -0.75 -5.89, -0.99 -5.81, -1.24 -5.71, -1.47 -5.58, -1.70 -5.43, -1.93 -5.26, -2.14 -5.07, -2.35 -4.85, -2.55 -4.62, -2.74 -4.37, -2.92 -4.11, -3.08 -3.82, -3.24 -3.53, -3.38 -3.21, -3.51 -2.89, -3.62 -2.55, -3.72 -2.21, -3.80 -1.85, -3.87 -1.49, -3.93 -1.12, -3.97 -0.75, -3.99 -0.38, -4.00 0.00))"
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Set createEllipse = reader.read(wkt)
	End Function
	
	Function createRectangle(llX, llY, width, height)
		Dim wkt
		wkt = "POLYGON ((" & CStr(llX) & " " & CStr(llY) & ", " & CStr(llX) & " " & CStr(llY + height) & ", " & CStr(llX+width) & " " & CStr(llY + height) & ", " & CStr(llX+width) & " " & CStr(llY) & ", " & CStr(llX) & " " & CStr(llY) & "))"
MsgBox wkt
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Set createRectangle = reader.read(wkt)
	End Function
	
	Function createArc(llX, llY, width, height, startang, endang)
		Dim wkt
		wkt = "LINESTRING (5.00 20.00, 5.00 20.00, 5.00 20.00, 5.50 20.00, 5.50 20.00, 5.50 20.00, 5.50 20.00, 5.50 20.00, 5.50 20.00, 6.00 20.00, 6.00 20.00, 6.00 20.00, 6.00 20.00, 6.00 20.00, 6.00 19.50, 6.00 19.50, 6.50 19.50, 6.50 19.50, 6.50 19.50, 6.50 19.50, 6.50 19.50, 6.50 19.50, 7.00 19.50, 7.00 19.50, 7.00 19.00, 7.00 19.00, 7.00 19.00, 7.00 19.00, 7.00 19.00, 7.50 19.00, 7.50 19.00, 7.50 19.00, 7.50 18.50, 7.50 18.50, 7.50 18.50, 7.50 18.50, 7.50 18.50, 8.00 18.50, 8.00 18.00, 8.00 18.00, 8.00 18.00, 8.00 18.00, 8.00 18.00, 8.00 17.50, 8.00 17.50, 8.50 17.50, 8.50 17.50, 8.50 17.50, 8.50 17.00, 8.50 17.00, 8.50 17.00, 8.50 17.00, 8.50 16.50, 9.00 16.50, 9.00 16.50, 9.00 16.50, 9.00 16.50, 9.00 16.00, 9.00 16.00, 9.00 16.00, 9.00 16.00, 9.00 15.50, 9.00 15.50, 9.00 15.50, 9.50 15.00, 9.50 15.00, 9.50 15.00, 9.50 15.00, 9.50 14.50, 9.50 14.50, 9.50 14.50, 9.50 14.50, 9.50 14.00, 9.50 14.00, 9.50 14.00, 9.50 13.50, 9.50 13.50, 9.50 13.50, 9.50 13.00, 10.00 13.00, 10.00 13.00, 10.00 13.00, 10.00 12.50, 10.00 12.50, 10.00 12.50, 10.00 12.00, 10.00 12.00, 10.00 12.00, 10.00 11.50, 10.00 11.50, 10.00 11.50, 10.00 11.50, 10.00 11.00, 10.00 11.00, 10.00 11.00, 10.00 10.50, 10.00 10.50, 10.00 10.50, 10.00 10.00, 10.00 10.00)"
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Set createArc = reader.read(wkt)
	End Function
	
	Function createGeoms()
		Dim geoms
		Set geoms = Array( _
			createPoint(150, 350), _
			createSquareLinearRing(0, 0, 100), _
			createUshapedLineString(60, 60, 100), _
			createSquareLinearRing(0, 0, 100), _
			createSquarePolygon(0, 200, 300), _
			createSquarePolygon(0, 250, 300), _
			createSimpleCollection(Nothing), _
			createCircle(0, 0, 10), _
			createEllipse(0, 0, 8, 12), _
			createRectangle(-5, -5, 10, 10), _
			createRectangle(-5, -5, 10, 20), _
			createArc(0, 0, 10, 20, 0, Math.PI / 2) _
		)
		
		Set createGeoms = geoms
	End Function
	
	Function printGeoms(geoms)
		Dim geom
		For Each geom In geoms
			Dim wkt
			wkt = geos.geomToWkt(geom)
			WScript.Echo wkt
		Next
	End Function
End Class
