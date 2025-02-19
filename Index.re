Printf.printf("hi");

module Something = {
  [@react.component]
  let make = () => {
    let (count, setCount) = React.useState(() => 0);
    <div>
      <div>
        <button onClick={_ => setCount(c => c + 1)}>
          {React.string("increment")}
        </button>
      </div>
      <div> {React.int(count)} </div>
      <div>
        <button onClick={_ => setCount(c => c - 1)}>
          {React.string("decrement")}
        </button>
      </div>
    </div>;
  };
};

module App = {
  [@react.component]
  let make = () => <div> <Something /> </div>;
};

let node = ReactDOM.querySelector("#root");
switch (node) {
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
| Some(root) =>
  let root = ReactDOM.Client.createRoot(root);
  ReactDOM.Client.render(root, <App />);
};
