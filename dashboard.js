import React, { useEffect, useState } from "react";

export default function Dashboard() {
  const [data, setData] = useState([]);
  useEffect(() => {
    fetch("http://localhost:5000/api/health")
      .then(res => res.json())
      .then(setData);
  }, []);
  return (
    <div>
      <h2>Avionics Health Monitoring</h2>
      <table>
        <thead>
          <tr><th>Timestamp</th><th>Airspeed</th><th>Altitude</th><th>Temp</th><th>Anomaly</th></tr>
        </thead>
        <tbody>
          {data.map((row, i) => (
            <tr key={i}>
              <td>{row.timestamp}</td>
              <td>{row.airspeed}</td>
              <td>{row.altitude}</td>
              <td>{row.temp}</td>
              <td>{row.anomaly ? "Yes" : "No"}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
