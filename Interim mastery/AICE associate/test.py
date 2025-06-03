import pandas as pd

# 데이터 준비 (큰 이상치 + 중간 이상치 섞인 상태)
data = pd.DataFrame({'x': [10, 12, 13, 14, 15, 16, 17, 18, 19, 40, 42, 43, 44, 45, 100, 105]})

def get_outliers(df, col):
    q1 = df[col].quantile(0.25)
    q3 = df[col].quantile(0.75)
    iqr = q3 - q1
    lower = q1 - 1.5 * iqr
    upper = q3 + 1.5 * iqr
    outliers = df[(df[col] < lower) | (df[col] > upper)][col].tolist()

def remove_outliers(df, col):
    q1 = df[col].quantile(0.25)
    q3 = df[col].quantile(0.75)
    iqr = q3 - q1
    lower = q1 - 1.5 * iqr
    upper = q3 + 1.5 * iqr
    filtered = df[(df[col] >= lower) & (df[col] <= upper)]
    return filtered

# 1차 이상치 탐지 (원본 기준)
outliers_before, bounds_before = get_outliers(data, 'x')
print(f"1차 이상치(원본 데이터 기준): {outliers_before}")
print(f"1차 IQR 경계값: {bounds_before}")

# 1차 이상치 제거
data_after_1 = remove_outliers(data, 'x')

# 2차 이상치 탐지 (1차 제거 후 데이터 기준)
outliers_after, bounds_after = get_outliers(data_after_1, 'x')
print(f"2차 이상치(1차 이상치 제거 후): {outliers_after}")
print(f"2차 IQR 경계값: {bounds_after}")