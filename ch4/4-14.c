/* Date: 23/06/19
   Description: Define macro swap(t, x, y) that interchanges two arguments of type t */

#define swap(t, x, y) {     t _z; \
                            _z = x; \
                            x = y;  \
                            y = _z; }

