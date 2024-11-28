object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 390
  ClientWidth = 597
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CountResultLabel: TLabel
    Left = 455
    Top = 196
    Width = 6
    Height = 15
    Caption = '0'
  end
  object FileExtensionLabel: TLabel
    Left = 356
    Top = 83
    Width = 90
    Height = 15
    Caption = 'Choise extension'
  end
  object CountLabel: TLabel
    Left = 360
    Top = 196
    Width = 74
    Height = 15
    Caption = 'Count cluster:'
  end
  object DetectLabel: TLabel
    Left = 360
    Top = 175
    Width = 61
    Height = 15
    Caption = 'File system:'
  end
  object DetectResultLabel: TLabel
    Left = 455
    Top = 175
    Width = 29
    Height = 15
    Caption = 'None'
  end
  object fileNameLabel: TLabel
    Left = 355
    Top = 25
    Width = 91
    Height = 15
    Caption = 'Entry your device'
  end
  object Panel1: TPanel
    Left = 360
    Top = 104
    Width = 200
    Height = 65
    TabOrder = 7
  end
  object StartButton: TButton
    Left = 356
    Top = 217
    Width = 201
    Height = 66
    Caption = 'Start'
    TabOrder = 0
    OnClick = StartButtonClick
  end
  object ResStringTree: TVirtualStringTree
    Left = 16
    Top = 8
    Width = 321
    Height = 354
    ClipboardFormats.Strings = (
      'Plain text'
      'Unicode text')
    DefaultNodeHeight = 19
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    ScrollBarOptions.AlwaysVisible = True
    TabOrder = 1
    OnGetText = ResStringTreeGet
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 0
        Text = 'Cluster Number'
        Width = 99
      end
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 1
        Text = 'Content'
        Width = 137
      end>
  end
  object jpegButton: TRadioButton
    Left = 371
    Top = 115
    Width = 113
    Height = 17
    Caption = 'jpeg'
    Checked = True
    TabOrder = 2
    TabStop = True
  end
  object pdfButton: TRadioButton
    Left = 472
    Top = 115
    Width = 88
    Height = 17
    Caption = 'pdf'
    TabOrder = 3
  end
  object exeButton: TRadioButton
    Left = 371
    Top = 145
    Width = 113
    Height = 17
    Caption = 'exe'
    TabOrder = 4
  end
  object pngButton: TRadioButton
    Left = 472
    Top = 145
    Width = 88
    Height = 17
    Caption = 'png'
    TabOrder = 5
  end
  object StopButton: TButton
    Left = 356
    Top = 289
    Width = 201
    Height = 73
    Caption = 'Stop'
    TabOrder = 6
    OnClick = StopButtonClick
  end
  object DiskEdit1: TEdit
    Left = 355
    Top = 46
    Width = 205
    Height = 23
    TabOrder = 8
    Text = '\\.\C:'
  end
end
