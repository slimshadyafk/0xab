import Product from "./models/Product.js"
import bodyParser from "body-parser";
import express from "express";
import cors from "cors";

const app = express();
app.use(express.json());
app.use(bodyParser({}));
app.use(cors());

const PORT = 5000;

app.get("/products", async (req, res) => {
  const products = await Product.find();
  res.json(products);
});

app.post("/products", async (req, res) => {
  const newProduct = new Product(req.body);
  await newProduct.save();
  res.json(newProduct);
});

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
