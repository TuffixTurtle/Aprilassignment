//
//  utils.c
//  linked_list
//
//  Created by William McCarthy on 094//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#include "ulist.h"


//-------------------------------------------------
const char* yesorno(bool condition) {
  static char yes[] = "YES";
  static char no[]  = "NO";

  return condition ? yes : no;
}

/*Majority of code is cobyrighted to professor.*/
