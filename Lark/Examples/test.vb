Module Module1
    Sub Main()

	Dim Array(1000) As Integer
	Dim Size, I As Integer

	Console.Write("Input arrays size: ")
	Size = Console.ReadLine()

	Console.WriteLine("Generate array...")
	I = 0
	While I < Size
	    Array(I) = Size - I
	    I = I + 1
	End While

	'Array = BubbleSort(Array,Size)
	WriteArray(BubbleSort(Array,Size),Size)

    End Sub

    Function BubbleSort (ByRef Array() As Integer, ByVal S As Integer) As Integer()
	Dim I As Integer
	Dim J As Integer
	Dim Buff As Integer
	While I < S
	    While J < S - 1
		If Array(J) < Array(J + 1) Then
		    Buff = Array(J)
		    Array(J) = Array(J + 1)
		    Array(J + 1) = Buff
		End If
		J = J + 1
	    End While
	    I = I + 1
	End While
	Return Array
    End Function
    
    Sub WriteArray(ByRef Arr() As Integer, ByVal S As Integer)
	Dim J As Integer
	While J < S
	    Console.WriteLine(Arr(J))
	    J = J + 1
	End While
    End Sub

End Module
