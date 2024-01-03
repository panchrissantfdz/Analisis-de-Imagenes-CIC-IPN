object Medial_Axis: TMedial_Axis
  Left = 652
  Top = 192
  Width = 195
  Height = 246
  Caption = 'Medial Axis'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 40
    Width = 82
    Height = 19
    Caption = 'Orientaci'#243'n'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Roboto'
    Font.Style = []
    ParentFont = False
  end
  object OK: TButton
    Left = 48
    Top = 136
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKClick
  end
  object Vertical: TRadioButton
    Left = 32
    Top = 80
    Width = 113
    Height = 17
    Caption = 'Vertical'
    TabOrder = 1
  end
  object RadioButton2: TRadioButton
    Left = 32
    Top = 104
    Width = 113
    Height = 17
    Caption = 'Horizontal'
    TabOrder = 2
  end
end
