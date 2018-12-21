Sub 设置代码表格()
' author: code4101
' 设置代码表格 宏
'
'
    ' 背景色为morning的配色方案，RGB为(229,229,229)
    With Selection.Tables(1)
        With .Shading
            .Texture = wdTextureNone
            .ForegroundPatternColor = wdColorAutomatic
            .BackgroundPatternColor = 15066597
        End With
        .Borders(wdBorderLeft).LineStyle = wdLineStyleNone
        .Borders(wdBorderRight).LineStyle = wdLineStyleNone
        .Borders(wdBorderTop).LineStyle = wdLineStyleNone
        .Borders(wdBorderBottom).LineStyle = wdLineStyleNone
        .Borders(wdBorderVertical).LineStyle = wdLineStyleNone
        .Borders(wdBorderDiagonalDown).LineStyle = wdLineStyleNone
        .Borders(wdBorderDiagonalUp).LineStyle = wdLineStyleNone
        .Borders.Shadow = False
        .AutoFitBehavior (wdAutoFitContent)  '自动调整大小
    End With
    With Options
        .DefaultBorderLineStyle = wdLineStyleSingle
        .DefaultBorderLineWidth = wdLineWidth050pt
        .DefaultBorderColor = wdColorAutomatic
    End With
    
    ' 段落无首行缩进，行间距为固定值12磅
    With Selection.ParagraphFormat
        .LeftIndent = CentimetersToPoints(0)
        .RightIndent = CentimetersToPoints(0)
        .SpaceBefore = 0
        .SpaceBeforeAuto = False
        .SpaceAfter = 0
        .SpaceAfterAuto = False
        .LineSpacingRule = wdLineSpaceExactly
        .LineSpacing = 12
        .KeepWithNext = False
        .KeepTogether = False
        .PageBreakBefore = False
        .NoLineNumber = False
        .Hyphenation = True
        .FirstLineIndent = CentimetersToPoints(0)
        .OutlineLevel = wdOutlineLevelBodyText
        .CharacterUnitLeftIndent = 0
        .CharacterUnitRightIndent = 0
        .CharacterUnitFirstLineIndent = 0
        .LineUnitBefore = 0
        .LineUnitAfter = 0
        .MirrorIndents = False
        .TextboxTightWrap = wdTightNone
        .AutoAdjustRightIndent = True
        .DisableLineHeightGrid = False
        .FarEastLineBreakControl = True
        .WordWrap = True
        .HangingPunctuation = True
        .HalfWidthPunctuationOnTopOfLine = False
        .AddSpaceBetweenFarEastAndAlpha = True
        .AddSpaceBetweenFarEastAndDigit = True
        .BaseLineAlignment = wdBaselineAlignAuto
    End With
    ' 清除原有的段落底纹
    Selection.ParagraphFormat.Shading.BackgroundPatternColor = wdColorAutomatic
End Sub
 
Sub 输入连续数字()
' author: code4101
    行数 = InputBox("请输入代码终止行数", "输入行数", "50")
    For i = 1 To 行数 - 1
        Selection.TypeText Text:=i
        Selection.TypeParagraph
    Next
    Selection.TypeText Text:=行数
End Sub