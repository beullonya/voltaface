import './App.css';
import Container from '@mui/material/Container';
import Header from './components/Header';
import Contents from './components/Contents';
import Footer from './components/Footer';
// import Header from './components/H';


function App() {
  return (
    <Container fixed>
      <Header />
      <Contents />
      <Footer />
    </Container>
  );
}

export default App;
