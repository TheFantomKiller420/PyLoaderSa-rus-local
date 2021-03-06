import _opcodes
from typing import Tuple

class Mouse():
   @staticmethod
   def get_movement() ->  Tuple[float, float]:
      '''Gives the offset of the mouse or right thumbstick movement'''
      return _opcodes.get_pc_mouse_movement()

   @staticmethod
   def is_using_vertical_inversion():
      '''Returns true if the players settings are set to invert the mouse'''
      return _opcodes.is_mouse_using_vertical_inversion()

