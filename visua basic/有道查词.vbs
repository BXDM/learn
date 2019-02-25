' 1.将以下程式码复制到Excel VBA 模组(Module)中
'
' 2.在Excel工作表中A Column输入要批量翻译的生词列表
'
' 3.若要转出有道xml格式单词库文件，请执行xmlVocabulary，汇出的档案位置为Excel活页簿位置，档案名称为"工作表名称.xml"
'
' 4.若要批量翻译直接写入Excel档，请执行xlsmVocabulary
'
' 5.先以少量生词列表测试翻译速度，我自己1000个字大概花7~8分钟翻译
'
' 6.若要现成的Excel档，请网搜"有道单词本.xlsm"

Private Type Character
    word As String
    trans As String
    phonetic As String
    tags As String
    'progress As Integer
End Type

'汇出有道xml格式单词库文件
Sub xmlVocabulary()

    Dim newChar As Character
    Dim R As Range
    Dim Row As Range
    Dim strOutput As String
    Dim arrBytes() As Byte

    newChar.tags = ActiveSheet.name
    ActiveSheet.Names.Add name:="NewWord", RefersTo:="=OFFSET($A$1,0,0,COUNTA($A:$A))"
    Set R = ActiveSheet.Names("NewWord").RefersToRange
    
    strOutput = "<wordbook>"
    For Each Row In R.Rows
        newChar.word = Trim(Row(1))
        Call searchWord(newChar.word, newChar.trans, newChar.phonetic)
        strOutput = strOutput & vbCrLf & "<item>"
        strOutput = strOutput & vbCrLf & "<word>" & newChar.word & "</word>"
        strOutput = strOutput & vbCrLf & "<trans><![CDATA[" & newChar.trans & "]]></trans>"
        strOutput = strOutput & vbCrLf & "<phonetic><![CDATA[" & newChar.phonetic & "]]></phonetic>"
        strOutput = strOutput & vbCrLf & "<tags>" & newChar.tags & "</tags>"
        strOutput = strOutput & vbCrLf & "<progress>1</progress>"
        strOutput = strOutput & vbCrLf & "</item>"
    Next Row
    strOutput = strOutput & vbCrLf & "</wordbook>"
    
    arrBytes = ChrW(&HFEFF) & strOutput     '写入unicode文字码
    
    Open Application.ActiveWorkbook.Path & "\" & newChar.tags & ".xml" For Binary As #1      '建立xml格式档案
    Put #1, , arrBytes
    
    Close #1

End Sub

'单词音译写入Excel档
Sub xlsmVocabulary()

    Dim newChar As Character
    Dim R As Range
    Dim Row As Range
    Dim rr As Integer

    strTags = ActiveSheet.name
    ActiveSheet.Names.Add name:="NewWord", RefersTo:="=OFFSET($A$1,0,0,COUNTA($A:$A))"
    Set R = ActiveSheet.Names("NewWord").RefersToRange
    
    rr = 0
    
    For Each Row In R.Rows
        rr = rr + 1
        newChar.word = Trim(Row(1))
        
        Call searchWord(newChar.word, newChar.trans, newChar.phonetic)
        Worksheets(strTags).Cells(rr, 2).Value = newChar.phonetic   '撷取音标
        Worksheets(strTags).Cells(rr, 3).Value = newChar.trans      '撷取翻译
        
    Next Row
    
End Sub

    
    Sub searchWord(tmpWord As String, tmpTrans As String, tmpPhonetic As String)
    'http://dict.youdao.com/search?q=单词&keyfrom=dict.index
        Dim XH As Object
        Dim s() As String
        Dim str_tmp As String
        Dim str_base As String
        
        tmpTrans = ""
        tmpPhonetic = ""

        '开启网页
        Set XH = CreateObject("Microsoft.XMLHTTP")
        On Error Resume Next
        XH.Open "get", "http://dict.youdao.com/search?q=" & tmpWord & "&keyfrom=dict.index", False
        XH.send
        On Error Resume Next
        str_base = XH.responseText
        XH.Close
        Set XH = Nothing
        
        str_base = Split(Split(XH.responseText, "<div id=""webTrans"" class=""trans-wrapper trans-tab"">")(0), "<span class=""keyword"">")(1)

        '撷取音标
        If UBound(Split(str_base, "<span class=""pronounce"">美")) = 1 Then
        '美式音标
            tmpPhonetic = Split((Split(Split(str_base, "<span class=""pronounce"">美")(1), "<span class=""phonetic"">")(1)), "</span>")(0)
            On Error Resume Next
        Else
            tmpPhonetic = Split((Split(str_base, "<span class=""phonetic"">")(1)), "</span>")(0)
            On Error Resume Next
        End If

        '撷取中文翻译
        str_tmp = Split((Split(str_base, "<div class=""trans-container"">")(1)), "</div>")(0)
        str_tmp = Split((Split(str_tmp, "<ul>")(1)), "</ul>")(0)
        s = Split(str_tmp, "<li>")
        tmpTrans = Split(s(LBound(s) + 1), "</li")(0)
        For i = LBound(s) + 2 To UBound(s)
            tmpTrans = tmpTrans & Chr(10) & Split(s(i), "</li")(0)
        Next

    End Sub