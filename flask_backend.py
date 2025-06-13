from flask import Flask, jsonify
import pandas as pd

app = Flask(__name__)

@app.route('/api/health')
def health():
    df = pd.read_csv('../simulation-data/simulation_data.csv')
    return jsonify(df.tail(10).to_dict(orient='records'))

if __name__ == "__main__":
    app.run(debug=True)
