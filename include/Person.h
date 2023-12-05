#include "Arduino.h"
#include <EEPROM.h>

class Person {
public:
  String name;
  String uid; 

// define any necessary inline functions... they are all inline anyways lol
  Person(){}
  Person(String n, String id) : name(n), uid(id) {
  }
  String getUID(){ return uid; }
  String getName() { return name; }

/* UNDER DEVELOPMENT*/
/*
  bool matchesStoredUID() {
    for (int i = 0; i < 10; i++) {
      if (uid[i] != EEPROM.read(i)) {
        return false; // UID doesn't match at this address
      }
    }
    return true; // UID matches at all addresses
  }
*/
};