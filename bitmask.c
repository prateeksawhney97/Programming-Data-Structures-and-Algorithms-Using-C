#include <assert.h>

/* Finish initializing the flags */

const short FLAG_ON          = 1 << 0; // 1  (0x01)
const short FLAG_MOVEMENT    = 1 << 1; // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04)
const short FLAG_ALIVE       = ;
const short FLAG_BROKEN      = ;
const short FLAG_EDIBLE      = 1 << 5; // 32 (0x20)

int main() {
  short attributes = 0;

  /* Set the attributes ON, TRANSPARENT, and BROKEN */

  assert(attributes == FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN);

  /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */

  assert(attributes == FLAG_ON | FLAG_ALIVE);

  /* Check if the ALIVE flag is set */
  assert(/* ??? */);

  /* Check if the BROKEN flag is not set */
  assert(/* ??? */);

  /* Modify so only the EDIBLE attribute is set */

  assert(attributes == FLAG_EDIBLE);
}
