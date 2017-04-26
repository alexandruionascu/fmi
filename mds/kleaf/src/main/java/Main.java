import io.vertx.core.Handler;
import io.vertx.core.Vertx;
import io.vertx.core.http.HttpServer;
import io.vertx.core.http.HttpServerResponse;
import io.vertx.ext.web.Router;


public class Main {
    public static void main(String[] args) {
        HttpServer server = Vertx.vertx().createHttpServer();
        Router router = Router.router(Vertx.vertx());

        router.get("/boss").handler(routingContext -> {
           routingContext.response().end("Alex e boss");
        });
        router.route("/hello").handler(routingContext -> {

            // This handler will be called for every request
            HttpServerResponse response = routingContext.response();
            response.putHeader("content-type", "text/plain");

            // Write to the response and end it
            response.end("Hello World from Vert.x-Web!");
        });

        server.requestHandler(router::accept).listen(8080);

    }
}
