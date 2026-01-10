import { useState, type JSX } from "react";
import "material-symbols";
import "./main_window.css";

export default function MainWindow(): JSX.Element {
  const [isDrawerOpen, setIsDrawerOpen] = useState(true);
  const toggleDrawer = () => setIsDrawerOpen(!isDrawerOpen);
  return (
    <>
      <div className="app-bar">
        <div className="app-bar-icon-btn" onClick={toggleDrawer}>
          <span className="material-symbols-rounded no-select">menu</span>
        </div>
        <b>Material3-QWidget Docs</b>
      </div>

      <div className="app-shell">
        <div className={`app-drawer ${isDrawerOpen ? "" : "hide"}`}>
          
        </div>
      </div>
    </>
  );
}