#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Comp;
const double PI = acos(-1);
const int N = 4.2e6;  // 最大处理长度

Comp f[N], g[N];      // 存储多项式系数的复数数组

/**
 * 快速傅里叶变换（递归版）
 * @param a     复数数组指针（输入多项式系数/输出点值）
 * @param n     变换长度（必须为2的幂）
 * @param op    变换方向：1=正向DFT，-1=逆向IDFT
 */
void FFT(Comp* a, int n, int op) {
    if (!n) return;
    Comp a0[n], a1[n];
    
    // 奇偶分组：将多项式分为偶数位和奇数位两部分
    for (int i = 0; i < n; i++) {
        a0[i] = a[i << 1];
        a1[i] = a[i << 1 | 1];
    }
    
    // 递归处理子问题
    FFT(a0, n >> 1, op);
    FFT(a1, n >> 1, op);
    
    // 合并子问题结果：应用旋转因子并组合
    Comp W(cos(PI / n), sin(PI / n) * op);  // 单位根 w_{2n}^1
    Comp w(1, 0);                            // 旋转因子初始化为 w_{2n}^0 = 1
    
    for (int i = 0; i < n; i++, w *= W) {
        a[i] = a0[i] + w * a1[i];          // 前半部分结果
        a[i + n] = a0[i] - w * a1[i];      // 后半部分结果（利用对称性）
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);   // IO优化：关闭同步流，加速输入输出

    // 输入多项式A和B的系数
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        double x; cin >> x;
        f[i] = Comp(x, 0);  // 实系数多项式，虚部为0
    }
    for (int i = 0; i <= m; ++i) {
        double x; cin >> x;
        g[i] = Comp(x, 0);  // 实系数多项式，虚部为0
    }

    // 计算最小扩展长度（2的幂，需覆盖A*B的最高次n+m）
    for (m += n, n = 1; n <= m; n <<= 1);

    // 正向FFT：系数表示 → 点值表示
    FFT(f, n >> 1, 1);
    FFT(g, n >> 1, 1);

    // 点值相乘：(A*B)的点值 = A的点值 * B的点值（O(n)复杂度）
    for (int i = 0; i < n; ++i) {
        f[i] *= g[i];
    }

    // 逆向FFT：点值表示 → 系数表示（需除以n归一化）
    FFT(f, n >> 1, -1);

    // 输出结果：四舍五入取实部（消除浮点误差）
    for (int i = 0; i <= m; ++i) {
        cout << (int)(fabs(f[i].real()) / n + 0.5) << " ";
    }
    cout << endl;

    return 0;
}