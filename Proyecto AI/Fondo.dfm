object Background: TBackground
  Left = 836
  Top = 192
  Width = 196
  Height = 247
  Caption = 'Background'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Completado: TLabel
    Left = 48
    Top = 56
    Width = 86
    Height = 19
    Caption = 'Completado'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Roboto'
    Font.Style = []
    ParentFont = False
  end
  object OK: TButton
    Left = 56
    Top = 112
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKClick
  end
end
