
# 공분산과 상관계수
자료간의 상관 관계를 나타낸다.

### Sample
#### sample covariance

$$s_{xy} = \dfrac{1}{N}\sum_{i=1}^{N} (x_i-m_x)(y_i-m_y)$$

자료가 평균값으로부터 얼마나 떨어져 있는지 나타냄. (방향과 거리 정보)
- 결합 분포의 평균을 중심으로 각 샘플들의 분포 양상을 보여준다.
- 각 샘플이 이루는 사각형 넓이의 평균
- $s_{xy} > 0$ : 양의 방향
- $s_{xy} < 0$ : 음의 방향

#### sample correlation coefficient

자료 분포의 방향성만 분리하여 표현

$$\text{Pearson:}\;\;r_{xy} = \dfrac{s_{xy}}{\sqrt{s^2_{x} \cdot s^2_{y}}}$$

### 학률 변수의 공분산, 상관계수 (Ideal)

$$\text{Cov}[X, Y] = \text{E}[(X - \text{E}[X])(Y - \text{E}[Y])]$$

$$\rho[X,Y] =  \dfrac{\text{Cov}[X, Y]}{\sqrt{\text{Var}[X] \cdot \text{Var}[Y]}}$$

$$-1 \leq \rho \leq 1$$

$\rho = 0$ : 무상관 (독립을 의미하지 않음)


## 다변수 확률 변수의 공분산

- 샘플 공분산

확률 변수 $X$가 다변수 확률 변수인 경우, 샘플 공분산 행렬을 정의(Sample covariance Matrix)

$X_0$는 평균을 제거하여 샘플 평균이 0이 된 데이터 행렬을 의미. $N$은 데이터의 갯수.
$$S = \dfrac{1}{N} X_0^TX_0$$

$$\mu = \dfrac{1}{N} X^T\mathbf{1_N}$$

$$X_0 = X - \mathbf{1_M}\mu^T$$

$\mathbf{1_N}$은 $N$차원 일벡터.


- 이론적 공분산

이론적 공분산 행렬은 $\Sigma$로 표기하며, 다음과 같의 정의.

$$ \Sigma = \text{Cov}[X] = \text{E} \left[ (X - \text{E}[X])(X - \text{E}[X])^T \right] $$

$$=
\begin{bmatrix}
\sigma_{x_1}^2     \;\;  &  \sigma_{x_1x_2} \;\;&  \sigma_{x_1x_3} \;\;&  \cdots &  \sigma_{x_1x_M} \\
\sigma_{x_1x_2}   \;\;    &  \sigma_{x_2}^2 \;\;&  \sigma_{x_2x_3} \;\;&  \cdots &  \sigma_{x_2x_M} \\
\vdots       &  \vdots &  \vdots &  \ddots &  \vdots \\
\sigma_{x_1x_M}   \;\;    &  \sigma_{x_2x_M} \;\;&  \sigma_{x_3x_M} \;\;&  \cdots &  \sigma_{x_M}^2 \\
\end{bmatrix}$$
