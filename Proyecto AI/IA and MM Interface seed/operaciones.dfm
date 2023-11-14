object FormArithmeticOperations: TFormArithmeticOperations
  Left = 679
  Top = 93
  BorderStyle = bsToolWindow
  Caption = 'Arithmetic Operations'
  ClientHeight = 431
  ClientWidth = 273
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel2: TBevel
    Left = 144
    Top = 8
    Width = 121
    Height = 121
  end
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 121
    Height = 121
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 105
    Height = 105
    Stretch = True
  end
  object Image2: TImage
    Left = 152
    Top = 16
    Width = 105
    Height = 105
    Stretch = True
  end
  object GroupBox1: TGroupBox
    Left = 40
    Top = 240
    Width = 201
    Height = 81
    TabOrder = 0
    object RadioButtonLimited: TRadioButton
      Left = 8
      Top = 56
      Width = 57
      Height = 17
      Caption = 'Limited'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButtonCyclic: TRadioButton
      Left = 144
      Top = 56
      Width = 49
      Height = 17
      Caption = 'Cyclic'
      TabOrder = 1
    end
    object RadioButtonScaled: TRadioButton
      Left = 72
      Top = 56
      Width = 57
      Height = 17
      Caption = 'Scaled'
      TabOrder = 2
    end
    object ButtonAdd: TButton
      Left = 8
      Top = 16
      Width = 41
      Height = 33
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = ButtonAddClick
    end
    object ButtonSubtract: TButton
      Left = 56
      Top = 16
      Width = 41
      Height = 33
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = ButtonSubtractClick
    end
    object ButtonMultiplication: TButton
      Left = 104
      Top = 16
      Width = 41
      Height = 33
      Caption = '*'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = ButtonMultiplicationClick
    end
    object ButtonDivision: TButton
      Left = 152
      Top = 16
      Width = 41
      Height = 33
      Caption = '/'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = ButtonDivisionClick
    end
  end
  object BitBtnI1: TBitBtn
    Left = 32
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Image 1'
    TabOrder = 1
    OnClick = BitBtnI1Click
  end
  object BitBtnI2: TBitBtn
    Left = 168
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Image 2'
    TabOrder = 2
    OnClick = BitBtnI2Click
  end
  object GroupBox2: TGroupBox
    Left = 56
    Top = 168
    Width = 161
    Height = 65
    TabOrder = 3
  end
  object CheckBoxFitSizeImage: TCheckBox
    Left = 64
    Top = 184
    Width = 145
    Height = 17
    Caption = 'Fit to the size of the image'
    TabOrder = 4
    OnClick = CheckBoxFitSizeImageClick
  end
  object RadioButtonImage1: TRadioButton
    Left = 72
    Top = 208
    Width = 65
    Height = 17
    Caption = 'Image 1'
    Checked = True
    Enabled = False
    TabOrder = 5
    TabStop = True
  end
  object RadioButtonImage2: TRadioButton
    Left = 144
    Top = 208
    Width = 65
    Height = 17
    Caption = 'Image 2'
    Enabled = False
    TabOrder = 6
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 328
    Width = 257
    Height = 97
    Caption = 'Image2 on Image1'
    TabOrder = 7
    object GroupBox4: TGroupBox
      Left = 88
      Top = 16
      Width = 161
      Height = 73
      Caption = 'Except pixels'
      TabOrder = 0
      object RadioButtonBlack: TRadioButton
        Left = 8
        Top = 16
        Width = 49
        Height = 17
        Caption = 'Black'
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = RadioButtonBlackClick
      end
      object RadioButtonWhite: TRadioButton
        Left = 8
        Top = 32
        Width = 49
        Height = 17
        Caption = 'White'
        TabOrder = 1
        OnClick = RadioButtonWhiteClick
      end
      object RadioButtonOtherColor: TRadioButton
        Left = 8
        Top = 48
        Width = 57
        Height = 17
        Caption = 'Other'
        TabOrder = 2
        OnClick = RadioButtonOtherColorClick
      end
      object BitBtnChooseColor: TBitBtn
        Left = 80
        Top = 16
        Width = 75
        Height = 25
        Caption = 'Choose Color'
        TabOrder = 3
        OnClick = BitBtnChooseColorClick
      end
      object PanelColor: TPanel
        Left = 80
        Top = 48
        Width = 75
        Height = 17
        TabOrder = 4
      end
    end
    object ButtonSuperimpose: TButton
      Left = 8
      Top = 32
      Width = 73
      Height = 25
      Caption = 'Superimpose'
      TabOrder = 1
      OnClick = ButtonSuperimposeClick
    end
  end
  object ColorDialogSuperimpose: TColorDialog
    Ctl3D = True
    Left = 232
    Top = 184
  end
end
