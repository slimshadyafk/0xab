import React from "react";

const issues = [
  {
    id: 1,
    title: "Bug in Login",
    description: "Error 404 on login",
    status: "Open",
  },
  {
    id: 2,
    title: "UI Issue on Dashboard",
    description: "Misaligned elements",
    status: "Closed",
  },
  {
    id: 3,
    title: "API Timeout",
    description: "Delayed response from server",
    status: "Open",
  },
];


export default function IssueList() {
  return (
    <div>
      <ol>
        {issues.map((item, index) => (
          <li key={item.id}>
              <h2>{item.title}</h2>
              <p>{item.description}</p>
              <p>{item.status}</p>
          </li>
        ))}
      </ol>
    </div>
  );
}
