import type { Route } from "./+types/home";
import MainWindow from "../main_window/main_window";

export function meta({}: Route.MetaArgs) {
  return [
    { title: "New React Router App" },
    { name: "description", content: "Welcome to React Router!" },
  ];
}

export default function Home() {
  return <MainWindow />;
}
