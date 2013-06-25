object MainForm: TMainForm
  Left = 450
  Top = 156
  Caption = #1055#1088#1086#1075#1085#1086#1079#1080#1088#1086#1074#1072#1085#1080#1077' '#1085#1072' '#1086#1089#1085#1086#1074#1077' '#1085#1077#1095#1105#1090#1082#1080#1093' '#1088#1077#1075#1088#1077#1089#1089#1080#1086#1085#1085#1099#1093' '#1084#1086#1076#1077#1083#1077#1081
  ClientHeight = 551
  ClientWidth = 924
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 924
    Height = 551
    ActivePage = TabSheetRegMatrix
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 8
    ExplicitTop = 89
    ExplicitWidth = 633
    ExplicitHeight = 392
    object TabSheetRegMatrix: TTabSheet
      Caption = #1056#1077#1075#1088#1077#1089#1089#1080#1086#1085#1085#1099#1077' '#1084#1072#1090#1088#1080#1094#1099
      ExplicitLeft = 0
      ExplicitTop = 28
      object LabelXTX: TLabel
        Left = 77
        Top = 20
        Width = 76
        Height = 33
        Caption = '(Xt)*X'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelRXTX: TLabel
        Left = 256
        Top = 20
        Width = 121
        Height = 33
        Caption = '(Xt*X)^-1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelCoef: TLabel
        Left = 432
        Top = 30
        Width = 221
        Height = 23
        Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' '#1088#1077#1075#1088#1077#1089#1080#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object LabelReg: TLabel
        Left = 16
        Top = 276
        Width = 412
        Height = 33
        Caption = #1052#1072#1090#1088#1080#1094#1072' '#1088#1077#1075#1088#1077#1089#1089#1080#1080' (Xt*X)^1)(Xt)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object SGXTX: TStringGrid
        Left = 16
        Top = 59
        Width = 137
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 0
      end
      object SGRXTX: TStringGrid
        Left = 224
        Top = 59
        Width = 137
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 1
      end
      object SGReg: TStringGrid
        Left = 16
        Top = 315
        Width = 137
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 2
      end
      object SGCoef: TStringGrid
        Left = 472
        Top = 59
        Width = 134
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 3
      end
    end
    object TabSheetDiverse: TTabSheet
      Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1086#1090#1082#1083#1086#1085#1077#1085#1080#1081' '#1084#1086#1076#1077#1083#1080
      ImageIndex = 1
      ExplicitWidth = 281
      ExplicitHeight = 165
      object SGDiverse: TStringGrid
        Left = 507
        Top = 0
        Width = 70
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 0
      end
      object SGYP: TStringGrid
        Left = 352
        Top = 0
        Width = 137
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 1
      end
      object SGY: TStringGrid
        Left = 200
        Top = 0
        Width = 137
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 2
      end
      object SGX: TStringGrid
        Left = 8
        Top = 8
        Width = 137
        Height = 137
        DefaultColWidth = 24
        FixedCols = 0
        FixedRows = 0
        TabOrder = 3
      end
    end
    object TabSheetGraph: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082' '#1088#1077#1075#1088#1077#1089#1089#1080#1080
      ImageIndex = 2
      ExplicitWidth = 369
      ExplicitHeight = 165
      object ImageGraph: TImage
        Left = 3
        Top = 0
        Width = 798
        Height = 466
      end
    end
  end
  object MainMenu: TMainMenu
    Left = 856
    Top = 16
    object NFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object NQuit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = NQuitClick
      end
    end
    object NRegression: TMenuItem
      Caption = #1056#1072#1072#1089#1105#1090' '#1084#1086#1076#1077#1083#1080
      OnClick = NRegressionClick
    end
    object NProrerties: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    end
    object NGraph: TMenuItem
      Caption = #1055#1086#1089#1090#1088#1086#1077#1085#1080#1077' '#1075#1088#1072#1092#1080#1082#1086#1074
      OnClick = NGraphClick
      object NDepGrad: TMenuItem
        Caption = #1043#1088#1072#1076#1080#1077#1085#1090
        OnClick = NDepGradClick
      end
    end
    object NHelp: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
    end
  end
end
