

function Copyright(props) {
    return (
      <Typography variant="body2" color="text.secondary" align="center" {...props}>
        {'Copyright © '}
        <Link color="inherit" href="/">
          Volteface
        </Link>{' '}
        {new Date().getFullYear()}
        {'.'}
      </Typography>
    );
  }