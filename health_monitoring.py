import pandas as pd
from sklearn.ensemble import IsolationForest

df = pd.read_csv('../simulation-data/simulation_data.csv')

model = IsolationForest(contamination=0.1)
df['anomaly'] = model.fit_predict(df[['airspeed','altitude','temp']])
print(df[df['anomaly']==-1])
df.to_csv('../simulation-data/simulation_data_with_ml.csv', index=False)
