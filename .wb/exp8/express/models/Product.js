import { model, Schema } from "mongoose";

const productSchema = new Schema({
    name: {type: String, required: true},
    price: {type: Number, required: true},
})

const Product = new model("Product", productSchema);

export default Product;