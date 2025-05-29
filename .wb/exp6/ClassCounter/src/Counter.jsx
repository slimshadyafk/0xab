import React, {Component} from "react";

class Counter extends Component{
    state = {number: 0};
   
    increment = ()=>{
        const value = this.state.number + 1;
        this.setState({number: value});
    }
    decrement = ()=>{
        const value = this.state.number - 1;
        this.setState({number: value});
    }
    double = ()=>{
        const value = this.state.number * 2;
        this.setState({number: value});
    }
    reset = ()=>{
        this.setState({number: 0});
    }
    render(){
        return (
          <div>
            <h1>{this.state.number}</h1>
            <div>
              <button onClick={this.increment}>Increment</button>
              <button onClick={this.decrement}>Decrement</button>
              <button onClick={this.double}>Double</button>
              <button onClick={this.reset}>Reset</button>
            </div>
          </div>
        );
    }
}

export default Counter;