object SaltnPepper: TSaltnPepper
  Left = 597
  Top = 224
  Width = 155
  Height = 227
  Caption = 'SaltnPepper'
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
    Left = 24
    Top = 56
    Width = 97
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
    Left = 32
    Top = 104
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKClick
  end
end
