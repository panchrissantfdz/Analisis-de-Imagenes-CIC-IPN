object FrmRes: TFrmRes
  Left = 619
  Top = 145
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'Spatial Resolution'
  ClientHeight = 175
  ClientWidth = 211
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
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 8
    Width = 65
    Height = 161
    Caption = 'Discreet'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      '2'
      '4'
      '8'
      '16'
      '32'
      '64'
      '128')
    ParentFont = False
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object GroupBox1: TGroupBox
    Left = 80
    Top = 8
    Width = 121
    Height = 57
    Caption = 'Continuous'
    TabOrder = 1
    object UpDown1: TUpDown
      Left = 97
      Top = 24
      Width = 16
      Height = 21
      Associate = Edit1
      Min = 0
      Max = 129
      Position = 2
      TabOrder = 0
      Wrap = False
      OnClick = UpDown1Click
    end
    object Edit1: TEdit
      Left = 8
      Top = 24
      Width = 89
      Height = 21
      TabOrder = 1
      Text = '2'
      OnChange = Edit1Change
    end
  end
  object BitBtnOK: TBitBtn
    Left = 104
    Top = 104
    Width = 75
    Height = 25
    TabOrder = 2
    OnClick = BitBtnOKClick
    Kind = bkOK
  end
end
