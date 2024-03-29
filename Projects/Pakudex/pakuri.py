# by Jose Reynaldo on 16/3/24


import math

class Pakuri:

    def __init__(self, species: str, level: int):

        self._species = species
        self._level = level
        self._attack = (len(species) * 7 + 11) % 16
        self._defense = (len(species) * 5 + 17) % 16
        self._stamina = (len(species) * 6 + 13) % 16
        self._cp = math.floor(self._attack * math.sqrt(self._defense) * math.sqrt(self._stamina) * level * .08)
        self._hp = math.floor(self._stamina * level / 6)

    def get_species(self):
        return self._species

    def get_attack (self):
        return self._attack

    def get_defense (self):
        return self._defense

    def get_stamina (self):
        return self._stamina

    def set_attack(self, new_attack: int):
        self._attack = new_attack

    @property
    def cp(self):
        self._cp = math.floor(self._attack * math.sqrt(self._defense) * math.sqrt(self._stamina) * self._level * .08)
        return self._cp

    @property
    def hp(self):
        self._hp = math.floor(self._stamina * self._level / 6)
        return self._hp

    @property
    def level(self):
        return self._level

    @level.setter
    def level(self, new_level: int):
        self._level = new_level



