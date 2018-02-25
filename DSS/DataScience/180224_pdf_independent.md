# 확률 밀도 함수의 독립

확률 변수 X, Y의 joint pdf가 marginal pdf의 곱으로 나타나면 두 확률 변수가 서로 독립이다.

$$f_{XY}(x,y)=f_x(x)f_y(y) $$

### 반복 시행

같은 확률 변수에서 반복적으로(여러개의) sample을 취하는 경우 독립인 두 개의 확률 변수에서 나온 표본으로 취급.
ex. dice, coin

$$f(x_1, x_2, cdots, x_N) = \prod_{i=1}^{N} f(x_i)$$

### 조건부 확률 분포

독립인 두 확률 변수 $X,\;Y$의 조건부 확률 밀도 함수는 주변 확률 밀도 함수와 같다.
$$f_{X \mid Y} (x | y) = \dfrac{f_{XY}(x, y)}{f_{Y}(y)} = \dfrac{f_{X}(x) f_{Y}(y)}{f_{Y}(y)} = f_{X}(x)$$

### Moment
독립인 두 확률 변수 $X, Y$

$$\text{E}[XY] = \text{E}[X]\text{E}[Y]$$

$$\text{E}[(X - \mu_X)(Y-\mu_Y)] = 0$$

$$\text{Var}[X+Y] = \text{Var}[X] + \text{Var}[Y]$$
