import React, {useState, useEffect} from "react";

export default function Counter(){
    const [count, setCount] = useState(0);

    useEffect(()=>{
        setCount(0);
    }, []);
    
    return(
       <div>
            <h1>{count}</h1>
            <div>
                <button onClick={()=>setCount(count+1)}>Increment</button>
                <button onClick={()=>setCount(count-1)}>Decrement</button>
                <button onClick={()=>setCount(count*2)}>Double</button>
                <button onClick={()=>setCount(0)}>Reset</button>
            </div>
       </div> 
    );

}
