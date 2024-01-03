object Noise: TNoise
  Left = 175
  Top = 194
  Width = 356
  Height = 233
  Caption = 'Noise'
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
    Width = 196
    Height = 19
    Caption = 'Escoja el valor  de Varianza'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Roboto'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 208
    Top = 136
    Width = 75
    Height = 25
    HelpType = htKeyword
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Valor: TEdit
    Left = 72
    Top = 96
    Width = 185
    Height = 21
    TabOrder = 2
  end
end
