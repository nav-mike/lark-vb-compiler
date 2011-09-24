'This is example's program for demonstration Visual Basic language.
Module Module1

    ' Enum creates type of output's messages
    Enum TypeOfText
        OnlyDigits = 0
        WithText = 1
        None = 10
    End Enum

    'Main function
    Sub Main()

        Console.Title = "Demonstration of the Visual Basic language"

        Dim Count() As Integer = {5, 10, 17}
        Dim j As Integer = 0
        Try
            Do
                Dim TArr() As Integer = InitArray(Count(j))
                PrintArray(TArr, Count(j), TypeOfText.WithText, "Data")
                TArr = SortArray(TArr, Count(j))
                PrintArray(TArr, Count(j), TypeOfText.OnlyDigits, "")
                j += 1
            Loop Until j = 3
        Catch ex As Exception
            Console.WriteLine(ex.Message)
        End Try

        Console.ReadKey()

    End Sub

    'Function creates array of integer numbers
    Function InitArray(ByVal N As Integer) As Integer()
        Dim Result(N) As Integer
        Dim i As Integer

        For i = 0 To N
            Result(i) = N - i
        Next

        Return Result
    End Function

    'Function prints array
    Sub PrintArray(ByVal array As Integer(), ByVal N As Integer, ByVal type As TypeOfText, ByVal text As String)
        If type = TypeOfText.OnlyDigits Then
            Print(array, N)
        ElseIf type = TypeOfText.WithText Then
            Print(array, N, text)
        Else
            Console.WriteLine("Unknown type")
            Throw New System.Exception("An exception has occurred.")
        End If
    End Sub

    'Function prints array without text (only digits)
    Sub Print(ByVal array As Integer(), ByVal N As Integer)
        Dim I As Integer

        For I = 0 To N
            Console.WriteLine(array(I))
        Next

    End Sub

    'Function prints arrya with text
    Sub Print(ByVal array As Integer(), ByVal N As Integer, ByVal text As String)

        For Each I As Integer In array
            Console.Write(text + ": ")
            Console.WriteLine(I)
        Next

    End Sub

    'Function sort input's array and return it
    Function SortArray(ByVal array As Integer(), ByVal N As Integer)
        Dim i As Integer
        While i < N - 1
            If array(i) > array(i + 1) Then
                Dim Temp As Integer = array(i)
                array(i) = array(i + 1)
                array(i + 1) = Temp
            End If
            i += 1
        End While
        Return array
    End Function

End Module
