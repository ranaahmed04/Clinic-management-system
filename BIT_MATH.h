

#define SET_BIT(REG,BIT) ((REG) |= (1 << (BIT)))
#define CLEAR_BIT(REG,BIT) ((REG) &= (~(1 << (BIT))))
#define GET_BIT(REG,BIT) (((REG) >> (BIT)) & 1)
#define TOGGLE_BIT(REG,BIT) ((REG) ^= (1 << (BIT)))