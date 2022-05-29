import pandas as pd

df1_columns = ["ticker", "index"]
df1_values = ["SPY", "S&P 500"]
df1 = pd.DataFrame([df1_values], columns=df1_columns)

df2_columns = ["ticker", "ter"]
df2_values = ["VNQ", "0.03%"]
df2 = pd.DataFrame([df2_values], columns=df2_columns)

result = df1.append(df2, ignore_index=True, sort=False)
print(f"{df1}")
print(f"{df2}")
print(f"{result}")
