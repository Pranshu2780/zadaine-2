import './App.css';
import React, { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';

const Todos=()=>{
  const dispatch = useDispatch();
  const todos=useSelector(state=>state.todos);
  const handleClick = id=>dispatch({
    type: 'DELETE_TODO',
    payload:id,
  })
  if(!todos || !todos.length ){
     return <p>
       Todo-List is Empty
     </p>
  }
  return(
    <ul>
      {todos.map(todo=><li onClick={()=>handleClick(todo.id) } > {todo.label}</li>)}
    </ul>
  )
};

const TodoInput=()=>{
  const dispatch = useDispatch();
  const [newTodo, setNewTodo] = useState();
  const handleChange = event=>{
       setNewTodo(event.target.value);
  }
  const handleClick = ()=>dispatch({
    type:'ADD_TODO',
    payload:{
      label:newTodo,
      id: Math.ceil(Math.random()*100),
    }
  });
  return(
    <div>
    <input value={newTodo}  onChange={handleChange} type="text" />
    <button onClick={handleClick} > ADD</button>
 
    </div>
     )
};

class App extends React.Component {
  render(){
  return (
    <div>
      <p>
        TODO-LIST
      </p>
      <Todos/>
      <TodoInput />
      {/* <header>
        <form>
          <input placeholder="Enter the text" id="input" />
          <button type="submit" >Add</button>
        </form>
      </header> */}
    </div>
  );
  }
}

export default App;
