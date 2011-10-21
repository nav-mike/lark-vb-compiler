'This is exaple for test bison's rules for "expr".
Module Module1
    'This is main procedure of this module.
    Sub Main()
        Dim xyz As Integer = 10
        Dim zxy As Char = "x"
        Dim yzx As String = "xxxyyyzzz"
        Dim _xy As Boolean = True
        Dim y_x As Integer

        y_x = xyz + 20
        xyz = y_x - 15
        y_x = xyz * 2
        xyz = y_x / 2
        y_x = xyz \ 2
        y_x = 2 ^ 2
        _xy = y_x > xyz
        _xy = y_x < xyz
        _xy = y_x >= xyz
        _xy = y_x <= xyz
        xyz += 10
        xyz -= 10
        xyz *= 2
        xyz /= 2
        xyz \= 2
        _xy = y_x <> xyz
        _xy = (True)
        xyz = -10
    End Sub
End Module