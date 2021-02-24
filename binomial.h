class Binomial {
private:
  float cft[3] {0, 1.0, 1.0};
  int pwr[3] {0, 1, 1};

public:
  Binomial() {
    cft[1] = 1.0;
    cft[2] = 1.0;
    pwr[1] = 1;
    pwr[2] = 1;
  }

  Binomial(float x) {
    cft[1] = x;
    cft[2] = 1.0;
    pwr[1] = 1;
    pwr[2] = 1;

  }
  
  Binomial(float x, int y) {
    cft[2] = 1.0;
    pwr[2] = 1;
    cft[1] = x;

    if (y < 1) {
      pwr[1] = 1;
    }
    else
    pwr[1] = y;
  }

  Binomial(float x, int y, float a) {
    pwr[2] = 1;
    cft[1] = x;
    cft[2] =a;

    if (y < 1) {
      pwr[1] = 1;
    }
    else
    pwr[1] = y;
  }

  Binomial(float x, int a, float y, int b) {
  cft[1] = x;
  cft[2] = y;

  if ((a < 1) && (b < 1)) {
    pwr[1] = 1;
    pwr[2] = 1;
  }
  else if ((a < 1) && (b >= 1)) {
    pwr[1] = 1;
    pwr[2] = b;
  }
  else if ((a >= 1) && (b < 1)) {
    pwr[1] = a;
    pwr[2] = 1;
  }
  else 
  pwr[1] = a;
  pwr[2] = b;
  }
  
// 3: GetCoeficient and GetPower must accept, as a parameter, an index of the term; first term has index '1', second has '2', anything else returns '-1'

  float GetCoefficient(int c) {
    if (cft[c] == cft[1])
    return cft[1];
    else if (cft[c] == cft[2])
    return cft[2];
    else
    return -1;
  }

  int GetPower(int d) {
    if (pwr[d] == pwr[1])
    return pwr[1];
    else if (pwr[d] == pwr[2])
    return pwr[2];
    else
    return -1;
  }

// 4: SetPower: set corresponding binomial's exponent to the arbitrary positive value; if not positive, set power to default '1'; return '0' if successfully set, otherwise return '-1'

  int SetPower(int e, int f) {

    if (((e == 1) || (e == 2))) {
      pwr[e] = f;
      return 0;
    }

    else if (f >= 0) {
      pwr[e] = f;
      return 0;
    }

    else
    return -1;
  }

// 5: Add, adds one binomial to the other; parameter should be constant reference to the other binomial object; result is saved in caller object (x). Must return '0' if successfully terminated, otherwise '-1'; if binomials have different power, return '-1'.

  int Add(Binomial x) {

    if (pwr[1] != x->pwr[1]) {
      return -1;
    }

    else if ((pwr[1] == x->pwr[1]) && (pwr[2] != x->pwr[2])) {
      cft[1] = cft[1] + x->cft[1];
      return 0;
    }

    else if ((pwr[1] == x->pwr[1]) && (pwr[2] == x->pwr[2])) {
      cft[1] = cft[1] + x->cft[1];
      cft[2] = cft[2] + x->cft[2];
      return 0;
    }

    else
    return -1;
  }

// 6: First Multiply needs to accept floating parameter, used to perform multiplication of real number on binomial
// Second Multiply accepts a floating parameter and an integer; floating for monomial term coefficient value, integer for monomial term power

  void Multiply(float x) {
    cft[1] = cft[1] * x;
    pwr[1] = pwr[1];
    cft[2] = cft[2] * x;
    pwr[2] = pwr[2];
  }

  void Multiply(float x, int y) {
    cft[1] = pwr[1] + y;
    cft[2] = cft[2] * x;
    pwr[2] = pwr[2] + y;
  }
};

