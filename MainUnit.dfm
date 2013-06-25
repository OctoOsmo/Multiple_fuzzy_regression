object Form1: TForm1
  Left = 450
  Top = 156
  Caption = 'Form1'
  ClientHeight = 551
  ClientWidth = 924
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object ImageGraph: TImage
    Left = 426
    Top = 39
    Width = 458
    Height = 466
  end
  object SGX: TStringGrid
    Left = 16
    Top = 72
    Width = 137
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 0
  end
  object Button1: TButton
    Left = 296
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object SGXTX: TStringGrid
    Left = 224
    Top = 72
    Width = 137
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 2
  end
  object SGY: TStringGrid
    Left = 426
    Top = 72
    Width = 137
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 3
  end
  object SGRXTX: TStringGrid
    Left = 16
    Top = 329
    Width = 137
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 4
  end
  object SGReg: TStringGrid
    Left = 248
    Top = 329
    Width = 137
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 5
  end
  object SGYP: TStringGrid
    Left = 569
    Top = 72
    Width = 137
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 6
  end
  object StringGrid7: TStringGrid
    Left = 651
    Top = 329
    Width = 70
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 7
  end
  object ButtonGraph: TButton
    Left = 392
    Top = 8
    Width = 75
    Height = 25
    Caption = 'ButtonGraph'
    TabOrder = 8
    OnClick = ButtonGraphClick
  end
  object Draw: TButton
    Left = 488
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Draw'
    TabOrder = 9
    OnClick = DrawClick
  end
  object StringGrid8: TStringGrid
    Left = 727
    Top = 329
    Width = 70
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 10
  end
  object StringGrid9: TStringGrid
    Left = 803
    Top = 329
    Width = 70
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 11
  end
  object SGCoef: TStringGrid
    Left = 739
    Top = 72
    Width = 134
    Height = 137
    DefaultColWidth = 24
    FixedCols = 0
    FixedRows = 0
    TabOrder = 12
  end
  object MainMenu1: TMainMenu
    Left = 72
    Top = 16
    object NFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object NQuit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
      end
    end
  end
end
