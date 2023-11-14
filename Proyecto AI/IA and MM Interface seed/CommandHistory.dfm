object CommandHistoryForm: TCommandHistoryForm
  Left = 202
  Top = 156
  AutoScroll = False
  Caption = 'Command History'
  ClientHeight = 211
  ClientWidth = 370
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
    Width = 165
    Height = 13
    Caption = 'Select command[s] to undo or redo'
  end
  object Label2: TLabel
    Left = 32
    Top = 32
    Width = 37
    Height = 13
    Caption = 'Number'
  end
  object Label3: TLabel
    Left = 112
    Top = 32
    Width = 47
    Height = 13
    Caption = 'Command'
  end
  object ListBoxCommandHistory: TListBox
    Left = 8
    Top = 48
    Width = 345
    Height = 121
    IntegralHeight = True
    ItemHeight = 13
    TabOrder = 0
    OnClick = ListBoxCommandHistoryClick
  end
  object UndoRedoButton: TButton
    Left = 56
    Top = 176
    Width = 75
    Height = 25
    TabOrder = 1
    OnClick = UndoRedoButtonClick
  end
  object CancelButton: TButton
    Left = 152
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object HelpButton: TButton
    Left = 240
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Help'
    TabOrder = 3
  end
end
