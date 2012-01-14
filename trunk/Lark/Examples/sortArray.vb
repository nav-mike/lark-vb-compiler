Module Module1
    Sub Main()
        Dim Size As Integer = SetSize()
        Dim Array(100) As Integer
        Dim I, J As Integer
        For I = 0 To Size
            Array(I) = Size - I
        Next
        PrintArray(Array, Size)
        I = 0
        J = 0
        While I <= Size
            Do While J < Size - 1
                If Array(J) > Array(J + 1) Then
                    Dim Temp As Integer = Array(J)
                    Array(J) = Array(J + 1)
                    Array(J + 1) = Temp
                End If
                J = J + 1
            Loop
            I = I + 1
        End While
        Console.WriteLine()
        PrintArray(Array, Size)
    End Sub
    Function SetSize() As Integer
        Dim Size As Integer
        Console.WriteLine("Input array size:")
        Size = Console.ReadLine()
        Return Size
    End Function
	Sub PrintArray(ByVal Array() As Integer, ByVal Size As Integer)
        Dim I As Integer
        For I = 0 To Size
            Console.WriteLine(Array(I))
        Next
    End Sub
End Module