import React, { useEffect, useState } from "react";

function App() {
  const [products, setProducts] = useState([]);
  const [newProduct, setNewProduct] = useState({ name: "", price: "" });

  const fetchProducts = async () => {
    const res = await fetch("http://localhost:5000/products");
    const data = await res.json();
    setProducts(data);
  };

  useEffect(() => {
    fetchProducts();
  }, []);

  const addProduct = async () => {
    await fetch("http://localhost:5000/products", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(newProduct),
    });
    setNewProduct({ name: "", price: "" });
    fetchProducts(); 
  };

  return (
    <div>
      <h1>Product List</h1>

      <ul>
        {products.map((p) => (
          <li key={p._id}>
            {p.name} - ${p.price}
          </li>
        ))}
      </ul>

      <h2>Add Product</h2>
      <input
        type="text"
        placeholder="Name"
        value={newProduct.name}
        onChange={(e) => setNewProduct({ ...newProduct, name: e.target.value })}
      />
      <input
        type="number"
        placeholder="Price"
        value={newProduct.price}
        onChange={(e) =>
          setNewProduct({ ...newProduct, price: Number(e.target.value) })
        }
      />
      <button onClick={addProduct}>Add</button>
    </div>
  );
}

export default App;
