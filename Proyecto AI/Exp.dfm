object Exponencial: TExponencial
  Left = 174
  Top = 417
  Width = 356
  Height = 232
  Caption = 'Exponencial'
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
    Left = 64
    Top = 56
    Width = 194
    Height = 19
    Caption = 'Escoja el Valor de Varianza'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Roboto'
    Font.Style = []
    ParentFont = False
  end
  object Valor: TEdit
    Left = 72
    Top = 96
    Width = 185
    Height = 21
    TabOrder = 0
  end
  object Cancel: TButton
    Left = 32
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = CancelClick
  end
  object OK: TButton
    Left = 208
    Top = 136
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = OKClick
  end
end
