object NormalizeForm: TNormalizeForm
  Left = 640
  Top = 97
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'Normalize'
  ClientHeight = 101
  ClientWidth = 218
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 197
    Height = 13
    Caption = 'Write the pixels number for the longer side'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object GetNormalize: TEdit
    Left = 48
    Top = 32
    Width = 129
    Height = 21
    TabOrder = 0
    Text = '100'
  end
  object BitBtnOK: TBitBtn
    Left = 80
    Top = 64
    Width = 75
    Height = 25
    TabOrder = 1
    OnClick = BitBtnOKClick
    Kind = bkOK
  end
end
