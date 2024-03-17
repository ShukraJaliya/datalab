/* 
 * Lab 1 - Data Lab 
 * 
 * Student Name and Date: ******************************
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //checking for where it has mny boolean 
  int a = x & ~y; //negate x& y 
  int b = ~x & y; //nagate ~x& ~y
  int aXb= ~(~a & ~b);
  return aXb;

}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //inverrt x twice to check if x was 0;
  //increments x and XORs with inverted x to check for 0;
  //adds the expressions 

  return !((~x) ^(x+1)) & !!(~x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int odd =(0xAA << 8) + 0xAA;// odd is initialized to the 32-bit value 0xAA alternating 0 and 1 bits
  odd = (odd << 16) + odd; // adding keeps the add unchanged if x is even
  //XOR keeps the add unchanged if x is odd
  return !((x & odd)^ odd); 
  
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
 //inverts the bits
 //adding 1 over flowers all 1s to 0 only if  was 0
 //retuen result to check if x was 0 in a clever way
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int sign =1<<31;
  //creates a range from ~0x39  to ~0x30 by inverting sign to hex 
  int top = ~(sign | 0x39);
  int bottom= ~0x30; // iverts 0x30 to binary ofr bottom
  // extracts the sign bit after adding x 
  top =(sign&(top+x)) >>31; 
  //
  bottom =(sign& (bottom +1 +x)) >>31;

  return !(top |bottom);// returns true if within range. 
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //checkes if x and y have opposite signs 
  int xsign = (x >> 31)& 1;
  int ysign = (y >> 31)& 1;
  int difference = xsign ^ ysign; // calculates the XOR of the two signs 
  int xneg_ypos = difference & xsign; // checks if x is neg and y is pos. and extracts the where that is true
  int same_nonNeg= !difference &!((y + ~x+1)>> 31); // checks if both have same sign  and are not negative 
  

  return xneg_ypos | same_nonNeg;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
//flips x and adds 1 to check if x was 0 using ORs
  return ((x | (~x+1)) >> 31) +1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int a;
  int counts;
  int sign = x >> 31;
  x =(sign & (~x)) |(~sign & x); //flips the bits of x if it was negative
  a = !(x^0);//sets a to 1 if x was 0 originally, or 0 if x was non-zero
counts = (!!(x >>16)) << 4;
counts |= (!!(x >> (counts + 8))) <<3;
counts |= (!!(x >> (counts + 4))) <<2;
counts |= (!!(x >> (counts + 2))) <<1;
counts |= x >> (counts + 1);
//counts the leading 1 bits of a positve x handles the x==0 case, and adds 3.
//shifts x right in alopp, checking the new to bit each time. 
//increments counts if the top bit was 1.

  return counts +(~a) +3; 
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  //handles casses such as NaN, infinity
  unsigned sign = uf & 0x80000000; //extracts the sign bit
  int exp = uf & 0x7f800000;
  unsigned fraction = uf & 0x007FFFFF;

  if (exp == 0x7F800000)// checks for infinity
  return uf;

  if(exp ==0x0) //is a denormalized number so shits the fraction left 1
  return sign | (fraction << 1);

  if (exp == 0x7f000000) //the fraction is zero for infintiy outputs 
  fraction = 0x0;


  return sign| (exp+0x800000) | fraction;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  //scales fractions using exponent, rounds and sets the bit sign
  //converts a float's sign bit
  int sign = uf >> 31;
  int exp = (uf >> 23) & 0xFF;
  int frac = uf & 0x07FFFFF;
  int bias = 0x7F;
  int res = frac;

  if (exp == 0xFF) //checks for infinity 
    return 0x80000000; 

  if (exp < bias) // denormalized number or 0. 
    return 0;

  exp -= bias;

  if (exp > 31) //checks for overflow
    return 0x80000000;


  if (exp > 23) //shits left to scale up
    res <<= (exp - bias);
  else
    res >>= (bias - exp);

  res++;

  if (sign)
    return -res;
  else 
    return res;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  //it handles overlow and underflow conditions by reurning infity or 0.
  //shifts the signicant or fraction for deneromalized infputs 
  //shifts the sxponent into the right bit position for normal inputs 
  if(x< -126) {  //numbers with exponents less than -126 are denormalized/underlfow to 0/
    return 0; 
  }
  else if (x > 127) {//checks if ecpnents greater than 127overflow. and returns 0x7F800000
    return 0x7F800000;
  }
  else if (x >= -126 && x <= -1){//computes 2^x as a denormalized number by shifting the fraction left by x+ 127 bits
    return 1 << (x + 127);

  } 
  else {
    return (x + 127) << 23;

  } 
  
}
